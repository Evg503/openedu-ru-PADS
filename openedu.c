#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "openedu.h"

FILE *inf = NULL, *ouf = NULL;

void openedu_io_open() {
    inf = fopen("input.txt", "rt");
    ouf = fopen("output.txt", "wt");
}

void openedu_io_close() {
    fclose(inf);
    fclose(ouf);
}

int next_i32(int default_value) {
    int rv;
    return fscanf(inf, "%d", &rv) == 1 ? rv : default_value;
}

long long next_i64(long long default_value) {
    long long rv;
    return fscanf(inf, "%lld", &rv) == 1 ? rv : default_value;
}

double next_double(double default_value) {
    double rv;
    return fscanf(inf, "%lf", &rv) == 1 ? rv : default_value;
}

int next_bounded_impl(char *dest, int capacity, int skip_initial_ws) {
    int i, curr;
    if (capacity == 0) {
        return 0;
    }
    for (i = 0; i + 1 < capacity; ++i) {
        curr = fgetc(inf);
        if (i == 0 && skip_initial_ws) {
            while (curr <= ' ' && curr != EOF) {
                curr = fgetc(inf);
            }
        }
        if (curr == EOF || curr <= ' ') {
            dest[i] = '\0';
            return i;
        }
        dest[i] = (char) (curr);
    }
    dest[capacity - 1] = '\0';
    return capacity - 1;
}

int next_bounded(char *dest, int capacity) {
    return next_bounded_impl(dest, capacity, 1);
}

char *next_unbounded() {
    char stackbuf[16];
    int scan_size = next_bounded_impl(stackbuf, 16, 1);
    char *rv;
    if (scan_size < 15) {
        // don't forget to fit the '\0'
        rv = (char*) malloc(sizeof(char) * (scan_size + 1));
        memcpy(rv, stackbuf, sizeof(char) * (scan_size + 1));
        return rv;
    } else {
        int rv_size = (scan_size + 1) * 2;
        rv = (char*) malloc(sizeof(char) * rv_size);
        // not copying '\0'
        memcpy(rv, stackbuf, sizeof(char) * scan_size);
        while (1) {
            scan_size = scan_size + next_bounded_impl(rv + scan_size, rv_size - scan_size, 0);
            if (scan_size + 1 < rv_size) {
                return (char*) realloc(rv, scan_size + 1);
            }
            rv_size *= 2;
            rv = (char*) realloc(rv, rv_size);
        }
    }
}

int openedu_printf(char *fmt_string, ...) {
    int rv;
    va_list args;
    va_start(args, fmt_string);
    vfprintf(ouf, fmt_string, args);
    va_end(args);
    return rv;
}

void print(char *string) {
    fputs(string, ouf);
}

void println(char *string) {
    fputs(string, ouf);
    fputc('\n', ouf);
}

void print_char(char value) {
    fputc(value, ouf);
}

void print_i32(int value) {
    fprintf(ouf, "%d", value);
}

void print_i64(long long value) {
    fprintf(ouf, "%lld", value);
}

void print_double(double value) {
    fprintf(ouf, "%.17le", value);
}
