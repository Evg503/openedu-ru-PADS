#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>


    openedu_in in;
    openedu_out out;

void merge_sort(std::vector<int>& data, int b, int e, long long &inv){
  int d = e-b;
  if (d>1)
  {
    int s = (e+b)/2;
    merge_sort(data, b, s, inv);
    merge_sort(data, s, e, inv);

    std::vector<int> tmp;
    int i1 = b;
    int i2 = s;
    while(i1<s || i2<e)
    {
      if(data[i2]<data[i1])
      {
        inv += s-i1;
        //out.print_i32(s-i1).print("\n");
        tmp.push_back(data[i2++]);
      }
      else
      {
        tmp.push_back(data[i1++]);
      }
      if(i1 == s)
      {
        tmp.insert(tmp.end(), &data[i2], &data[e]);
        break;
      }
      if(i2 == e)
      {
        tmp.insert(tmp.end(), &data[i1], &data[s]);
        break;
      }
    }
    std::copy(tmp.begin(), tmp.end(), data.begin()+b);

   }

}


int main() {

    int n = in.next_i32(0);
    std::vector<int> data;
    data.reserve(n);
    for(int i = 0; i< n; ++i)
    {
    	data.push_back(in.next_i32(0));
    }

    long long inv = 0;
    merge_sort(data, 0, n, inv);
    out.print_i64(inv);
    return 0;
}
