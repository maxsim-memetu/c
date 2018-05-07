#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

ostream& formatDateTime(ostream& out, const tm& t, const char* fmt) {
	const time_put<char>& dateWriter = use_facet<time_put<char>>(out.getloc());
	int n = strlen(fmt);
	if(dateWriter.put(out, out, ' ',&t, fmt, fmt+n).failed()){
		throw runtime_error("fail to format date time");
	}
	return out; 
}
string dateTimeToString(const tm& t, const char* format) {
	stringstream s;
	formatDateTime(s, t, format);
	return s.str();
}

tm now() {
	time_t now = time(0);
	return *localtime(&now);
}

int main() {
	 try {
	 	string s = dateTimeToString(now(), "%A %B, %d %Y %I:%M%p");
	 	cout<<s<<endl;
	 	s = dateTimeToString(now(), "%Y-%m-%d %H:%M:%S");
	 	cout<<s<<endl;
	 } catch(...) {
	 	cerr<<"fail to format time"<<endl;
	 	return EXIT_FAILURE;
	 }
	 return EXIT_SUCCESS;
}