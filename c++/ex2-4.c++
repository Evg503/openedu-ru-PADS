#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

void part_sort(std::vector<int> &data, int l, int r, int k1, int k2)
{
  if( k2<l || k1>r) return;
  int key = data[(l+ r)/2];
  int i = l;
  int j = r;
  while(i<=j)
  {
    while (data[i] < key) ++i;
    while (key < data[j]) --j;
    if (i <= j)
    {
      std::swap(data[i], data[j]);
      ++i;
      --j;
    }
  }
  if (l < j) part_sort(data, l, j, k1, k2);
  if (i < r) part_sort(data, i, r, k1, k2);

}

int main() {
  openedu_in in;
  openedu_out out;

  int n = in.next_i32(0);
  int k1 = in.next_i32(0);
  int k2 = in.next_i32(0);
  int A = in.next_i32(0);
  int B = in.next_i32(0);
  int C = in.next_i32(0);

  std::vector<int> data;
  data.reserve(n);
  data.push_back(in.next_i32(0));
  data.push_back(in.next_i32(0));

  for(int i = 2; i< n; ++i)
  {
  	data.push_back(A*data[i-2] + B*data[i-1] +C);
  }
  // out.println(data.begin(), data.end());

  part_sort(data, 0, n-1, k1-1, k2-1);
  // out.println(data.begin(), data.end());
  out.println(data.begin()+k1-1, data.begin()+k2);
  return 0;
}


//5 3 4
//2 3 5 1 2
//out 13 48

//5 3 4
//200000 300000 5 1 2
//Out 	2 800005
