#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

int main() {
    openedu_in in;
     
    int n = in.next_i32(0);
    std::vector<int> a;
    std::vector<int> c;
    a.reserve(n);
    c.resize(n);
    for(int i = 0; i< n; ++i)
       a.push_back(in.next_i32(0));

   c[0] = 1;
   for(int i =1; i<n; i++)
	{
	    int j = i - 1;
	    while( j>=0 && a[j] > a[j+1])
	    {
		std::swap(a[j], a[j+1]);
		j--;
	    }
            c[i]=j+2; 	
	}
    openedu_out out;
    out.println(c.begin(), c.end());
    out.println(a.begin(), a.end());
    return 0;
}
