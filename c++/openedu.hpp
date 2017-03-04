#ifndef __OPENEDU_HPP__
#define __OPENEDU_HPP__

#include <string>

/**
 * An input wrapper for the C I/O library.
 */
struct openedu_in {
    openedu_in();
    ~openedu_in();

    /**
     * Reads a next signed int32. If fails, returns the default_value.
     */
    int next_i32(int default_value) const;
    /**
     * Reads a next signed int64. If fails, returns the default_value.
     */
    long long next_i64(long long default_value) const;
    /**
     * Reads a next double. If fails, returns the default_value.
     */
    double next_double(double default_value) const;
    /**
     * Reads a next whitespace-free token.
     */
    std::string next() const;
    /**
     * Reads a next int. If fails, leaves the reference unchanged.
     */
    openedu_in const &operator >> (int &target) const;
    /**
     * Reads a next long long. If fails, leaves the reference unchanged.
     */
    openedu_in const &operator >> (long long &target) const;
    /**
     * Reads a next double. If fails, leaves the reference unchanged.
     */
    openedu_in const &operator >> (double &target) const;
    /**
     * Clears and reads a next string.
     */
    openedu_in const &operator >> (std::string &target) const;
};

/**
 * An output wrapper for the C I/O library.
 */
struct openedu_out {
    openedu_out();
    ~openedu_out();

    /**
     * Writes the given signed int32 value.
     */
    openedu_out const &print_i32(int value) const;
    /**
     * Writes the given signed int64 value.
     */
    openedu_out const &print_i64(long long value) const;
    /**
     * Writes the given double value.
     */
    openedu_out const &print_double(double value) const;
    /**
     * Writes the given character.
     */
    openedu_out const &print_char(char value) const;
    /**
     * Writes the given C-string.
     */
    openedu_out const &print(char const *string) const;
    /**
     * Writes the given std::string.
     */
    openedu_out const &print(std::string const &string) const;
    /**
     * Writes the given C-string and appends a newline character.
     */
    openedu_out const &println(char const *string) const;
    /**
     * Writes the given std::string and appends a newline character.
     */
    openedu_out const &println(std::string const &string) const;
    /**
     * Writes the given collection of values, given by begin and end iterators,
     * whenever writing these values is supported by the << operator.
     * The values are separated by single whitespaces.
     */
    template<typename it>
        openedu_out const &print(it begin, it end) const
    {
        bool printed = false;
        while (begin != end) {
            if (printed) {
                print_char(' ');
            }
            (*this) << *begin++;
            printed = true;
        }
        return *this;
    }
    /**
     * Writes the given collection of values, given by begin and end iterators,
     * whenever writing these values is supported by the << operator.
     * The values are separated by single whitespaces. A newline character is appended.
     */
    template<typename it>
        openedu_out const &println(it begin, it end) const
    {
        print(begin, end);
        print_char('\n');
        return *this;
    }
    /**
     * Writes the given int.
     */
    openedu_out const &operator << (int value) const;
    /**
     * Writes the given long long.
     */
    openedu_out const &operator << (long long value) const;
    /**
     * Writes the given double.
     */
    openedu_out const &operator << (double value) const;
    /**
     * Writes the given character.
     */
    openedu_out const &operator << (char value) const;
    /**
     * Writes the given C-string.
     */
    openedu_out const &operator << (char const *value) const;
    /**
     * Writes the given std::string.
     */
    openedu_out const &operator << (std::string const &value) const;
};

#endif
