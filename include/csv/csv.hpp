////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Quick and dirty header-only CSV reader in C++17.
// https://github.com/PotatoMaster101/csv
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CSV_HPP
#define CSV_HPP
#include <string>
#include <vector>
#include <optional>
#include <fstream>      // std::ifstream
#include <sstream>      // std::istringstream
#include <ostream>      // std::ostream
#include <stdexcept>    // std::invalid_argument
#include <limits>       // std::numeric_limits
#include <ios>          // std::streamsize

namespace csv {

// Splits the given string `str` on delimiter `delim` (defaults to comma).
inline std::vector<std::string> csv_split(const std::string& str, char delim = ',') {
    std::vector<std::string> ret;
    std::string token;
    std::istringstream iss{str};
    while (std::getline(iss, token, delim))
        ret.push_back(token);
    return ret;
}

// Writes CSV data in the collection range specifed by `beg` and `end` to a file stream.
template <class Iter>
inline std::ostream& csv_write(std::ostream& os, Iter beg, Iter end) {
    while (beg != end) {
        os << *beg;
        os << ((++beg != end) ? "," : "\n");
    }
    return os;
}

// CSV reader.
class csv {
public:
    // Member types.
    using line_t = std::vector<std::string>;
    using lines_t = std::vector<line_t>;
    using optional_line_t = std::optional<line_t>;

    // Constructor.
    csv(const std::string& filename) : filename_{filename}, filestream_{filename}
    { if (!(filestream_.is_open())) throw std::invalid_argument{"filename"}; }

    // Rule of five.
    csv(const csv& rhs) = delete;               // don't copy file streams
    csv& operator=(const csv& rhs) = delete;    // don't copy file streams
    csv(csv&& rhs) noexcept = default;
    csv& operator=(csv&& rhs) noexcept = default;
    ~csv() noexcept = default;

    // Returns the CSV file name.
    inline const std::string& filename() const noexcept
    { return filename_; }

    // Returns whether EOF has reached.
    inline bool eof() const
    { return filestream_.eof(); }

    // Skip `n` lines from the CSV file (defaults to 1 line).
    inline void skip(std::size_t n = 1)
    { for (std::size_t i = 0; i < n && filestream_.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); i++); }

    // Reads and parses a line from the CSV file. Optional will be false if EOF reached.
    inline optional_line_t readline()
    { std::string line; return std::getline(filestream_, line) ? optional_line_t{csv_split(line)} : optional_line_t{}; }

    // Reads and parses `n` lines from the CSV file.
    inline lines_t readlines(std::size_t n = std::numeric_limits<std::streamsize>::max()) {
        lines_t ret;
        auto curr = readline();
        for (std::size_t i = 0; i < n && curr; i++) {
            ret.push_back(curr.value());
            curr = readline();
        }
        return ret;
    }
private:
    // CSV file name.
    std::string filename_;
    // CSV file stream.
    std::ifstream filestream_;
};

}   // namespace csv

#endif    // CSV_HPP
