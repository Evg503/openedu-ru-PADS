#ifndef __OPENEDU_H__
#define __OPENEDU_H__

/**
 * Initializes the library. Should be called before all other functions.
 */
void openedu_io_open();

/**
 * De-initializes the library. Should be called after all other functions.
 */
void openedu_io_close();

/**
 * Reads the next signed int32. If it fails, returns the default_value.
 */
int next_i32(int default_value);

/**
 * Reads the next signed int64. If it fails, returns the default_value.
 */
long long next_i64(long long default_value);

/**
 * Reads the next double. If it fails, returns the default_value.
 */
double next_double(double default_value);

/**
 * Reads at most (max_length - 1) symbols of the next whitespace-free token.
 * Returns the length of the token.
 */
int next_bounded(char *dest, int max_length);

/**
 * Reads the next whitespace-free token.
 */
char *next_unbounded();

/**
 * Prints the given signed int32 value.
 */
void print_i32(int value);

/**
 * Prints the given signed int32 value and puts a newline after it.
 */
void println_i32(int value);

/**
 * Prints the given signed int64 value.
 */
void print_i64(long long value);

/**
 * Prints the given signed int64 value and puts a newline after it.
 */
void println_i64(long long value);

/**
 * Prints the given double value.
 */
void print_double(double value);

/**
 * Prints the given double value and puts a newline after it.
 */
void println_double(double value);

/**
 * Prints the given character.
 */
void print_char(char value);

/**
 * Prints the given character and puts a newline after it.
 */
void println_char(char value);

/**
 * Prints the given string.
 */
void print(char *string);

/**
 * Prints the given string and puts a newline ('\n') after it.
 */
void println(char *string);

/**
 * Prints the text using the given format string and other arguments.
 * Usual conventions apply.
 */
int openedu_printf(char *fmt_string, ...);

#endif
