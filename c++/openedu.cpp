#include "openedu.hpp"

#include <cstdio>
#include <string>

FILE *inf, *ouf;
int inf_count = 0, ouf_count = 0;


openedu_in::openedu_in()
{
    if (inf_count == 0)
    {
        inf = fopen("input.txt", "rt");
    }
    ++inf_count;
}

openedu_in::~openedu_in()
{
    --inf_count;
    if (inf_count == 0)
    {
        fclose(inf);
    }
}

int openedu_in::next_i32(int default_value) const
{
    (*this) >> default_value;
    return default_value;
}

long long openedu_in::next_i64(long long default_value) const
{
    (*this) >> default_value;
    return default_value;
}

double openedu_in::next_double(double default_value) const
{
    (*this) >> default_value;
    return default_value;
}

std::string openedu_in::next() const
{
    std::string rv;
    (*this) >> rv;
    return rv;
}

openedu_in const &openedu_in::operator >> (int &target) const
{
    fscanf(inf, "%d", &target);
    return *this;
}

openedu_in const &openedu_in::operator >> (long long &target) const
{
    fscanf(inf, "%lld", &target);
    return *this;
}

openedu_in const &openedu_in::operator >> (double &target) const
{
    fscanf(inf, "%lf", &target);
    return *this;
}

openedu_in const &openedu_in::operator >> (std::string &target) const
{
    target.clear();
    while (true)
    {
        int ch = fgetc(inf);
        if (ch == EOF)
        {
            return *this;
        }
        if (ch > ' ')
        {
            target.push_back(ch);
            break;
        }
    }
    while (true)
    {
        int ch = fgetc(inf);
        if (ch == EOF || ch <= ' ')
        {
            return *this;
        }
        target.push_back(ch);
    }
}

openedu_out::openedu_out()
{
    if (ouf_count == 0)
    {
        ouf = fopen("output.txt", "wt");
    }
    ++ouf_count;
}

openedu_out::~openedu_out()
{
    --ouf_count;
    if (ouf_count == 0)
    {
        fclose(ouf);
    }
}

openedu_out const &openedu_out::print_i32(int value) const
{
    (*this) << value;
    return *this;
}

openedu_out const &openedu_out::print_i64(long long value) const
{
    (*this) << value;
    return *this;
}

openedu_out const &openedu_out::print_double(double value) const
{
    (*this) << value;
    return *this;
}

openedu_out const &openedu_out::print_char(char value) const
{
    (*this) << value;
    return *this;
}

openedu_out const &openedu_out::print(char const *string) const
{
    (*this) << string;
    return *this;
}

openedu_out const &openedu_out::print(std::string const &string) const
{
    (*this) << string;
    return *this;
}

openedu_out const &openedu_out::println(char const *string) const
{
    (*this) << string << '\n';
    return *this;
}

openedu_out const &openedu_out::println(std::string const &string) const
{
    (*this) << string << '\n';
    return *this;
}

openedu_out const &openedu_out::operator << (int value) const
{
    fprintf(ouf, "%d", value);
    return *this;
}

openedu_out const &openedu_out::operator << (long long value) const
{
    fprintf(ouf, "%lld", value);
    return *this;
}

openedu_out const &openedu_out::operator << (double value) const
{
    fprintf(ouf, "%.17lg", value);
    return *this;
}

openedu_out const &openedu_out::operator << (char value) const
{
    fputc(value, ouf);
    return *this;
}

openedu_out const &openedu_out::operator << (char const *value) const
{
    fputs(value, ouf);
    return *this;
}

openedu_out const &openedu_out::operator << (std::string const &value) const
{
    fputs(value.c_str(), ouf);
    return *this;
}
