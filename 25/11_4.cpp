#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
struct OutOfRange {
	OutOfRange(int min, int max): min_(min), max_(max) {}
	bool operator () (int x) { return (x < min_) || (x > max_);}
	int min_;
	int max_;
};
int main() {
	vector<int> vi;
	for(int i=0; i< 100; i++) {
		vi.push_back(i);
	}
	remove_copy_if(vi.begin(), vi.end(), ostream_iterator<int>(cout, "\n"), OutOfRange(50,60));// COPY those OutOfRange return false to cout(true is REMOVED)
}