#include <iostream>
#include "stride_iter.hpp"

using namespace std;

int main() {
	cout<<"hw"<<endl;
	int a[] = {0,1,2,3,4,5,6,7,8,9,10};
	stride_iter<int*> first(a, 2);
	stride_iter<int*> last(a+8, 2);
	cout<<*first<<endl;
	cout<<(first < last)<<endl;
	for(;first<last;first++) {
		cout<<*first<<endl;
		cout<<"suso"<<endl;
	}
	return 0;

}