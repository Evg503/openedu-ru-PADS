#include "openedu.hpp"
#include <vector>
#include <deque>
#include <array>
#include <map>
#include <algorithm>

openedu_in in;
openedu_out out;
extern FILE *inf, *ouf;

int main(int argc, char const *argv[]) {
  int n = in.next_i32(0);
  std::vector<int> v;
  v.reserve(n/2);

  std::string buf;
  buf.resize(2*n+2);
  int s = fread(&buf[0], 1, buf.size(), inf);
  buf.resize(s);
  int r2;
  int i = 0;
  while(buf[i] <=' ') ++i;
  for(; i<s; i+=2)
  {
    char c = buf[i];
    switch (buf[i] ) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        v.push_back(c-'0');
        break;
      case '+':
        r2 = v.back();
        v.pop_back();
        v.back()+=r2;
        break;
      case '-':
        r2 = v.back();
        v.pop_back();
        v.back()-=r2;
        break;
      case '*':
        r2 = v.back();
        v.pop_back();
        v.back()*=r2;
        break;

    }
  }
  out << v.back();
  return 0;
}
/**
7
8 9 + 1 7 - *
*/
