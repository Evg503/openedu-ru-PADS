#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

int main() {
    openedu_in in;
    openedu_out out;
    int n = in.next_i32(0);
    std::vector<int> data;
    data.reserve(n);

    if (n>0) data.push_back(1);
    if (n>1) data.push_back(2);
    for( int i = 2; i < n; ++i)
    {
      data.push_back(i+1);
      int m = i/2;
      std::swap(data[m], data[i]);
    }
    out.println(data.begin(), data.end());
    return 0;
}
