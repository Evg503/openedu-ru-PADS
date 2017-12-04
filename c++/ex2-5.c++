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
int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int main() {
  openedu_in in;
  openedu_out out;

  int n = in.next_i32(0);
  int k = in.next_i32(0);
  int nod = gcd(n, k);


  int n1 = n/nod;
  std::vector<std::vector<int> > datas;
  datas.resize(nod);

  for(int i = 0; i< n; ++i)
  {
    datas[i%nod].push_back(in.next_i32(0));
  }

  for(int i = 0; i< nod; ++i)
  {
    std::sort(datas[i].begin(), datas[i].end());
  }

  for(int i = 0; i<n1;++i)
  {
    for(int j = 0; j< nod-1; ++j)
    {
      if(datas[j+1].size()<i && datas[j][i]>datas[j+1][i])
      {
        out.print("NO");
        return 0;
      }
    }
  }
  for(int j = 0; j< nod; ++j)
    out.println(datas[j].begin(), datas[j].end());
  out.print("YES");
  return 0;
}

/*
3 2
2 1 3

 	NO

5 3
1 5 3 4 1

	YES
*/
