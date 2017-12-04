#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>


    openedu_in in;
    openedu_out out;

void merge_sort(std::vector<int>& data, int b, int e){
   int d = e-b;
   //out.print_char('>').print_i32(b).print_char('-').print_i32(e).print_char('\n');
   if (d>1){
	int s = (e+b)/2;
	merge_sort(data, b, s);
	merge_sort(data, s, e);

	std::vector<int> tmp;
	int i1 = b;
	int i2 = s;
	while(i1<s || i2<e)
	{
	  //out.print("i1=").print_i32(i1).print(" i2=").print_i32(i2).print("\n");
	  if(data[i2]<data[i1])
		tmp.push_back(data[i2++]);
	  else
		tmp.push_back(data[i1++]);

	  if(i1 == s)
	  {
		//out.print("i1==s\n");
		tmp.insert(tmp.end(), &data[i2], &data[e]);
		break;
	  }
	  if(i2 == e)
	  {
		//out.print("i2==s\n");
		tmp.insert(tmp.end(), &data[i1], &data[s]);
		break;
	  }
	}
	//out.println(tmp.begin(), tmp.end());
	std::copy(tmp.begin(), tmp.end(), data.begin()+b);
	out.print_i32(b+1).print_char(' ').print_i32(e).print_char(' ');
	out.print_i32(data[b]).print_char(' ').print_i32(data[e-1]).print_char('\n');
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

    merge_sort(data, 0, n);  
    out.println(data.begin(), data.end());
    return 0;
}
