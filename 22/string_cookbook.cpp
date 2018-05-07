#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;

string padding(size_t size, string &orig, char pad) {
   string ret = orig.substr(0, size);
   size_t l = ret.length();
   if(l < size) {
      // for(auto k: size - l)
      //need padding
      // string p {size - l, pad};
      for(int k=0;k<size-l;k++) {
         ret += pad;
      }
      // ret.append(size - l, pad); // a more short implementation
   }
   return ret;
}
string strim(string orig, char trim_char) {
   string ret;
   string::iterator p;
   for(p=orig.begin(); p!=orig.end(); p++) {
      if(*p!=trim_char)
         ret.append(1,*p);
   }
   return ret;
}
int main( ) {
   string str1 = "750";
   string str2 = "2.71";
   string str3 = "0x7FFF";
   string str4 = "qwerty";
   string str5 = "abcccccd";
   try {
      cout << boost::lexical_cast<int>(str1) << endl;
      cout << boost::lexical_cast<double>(str2) << endl;
      // cout << boost::lexical_cast<int>(str3) << endl;
      cout<<str1.length()<<endl;
      cout<<padding(10, str4, '*')<<endl;
      cout<<strim(str5, 'c')<<endl;
   }
   catch (boost::bad_lexical_cast& e) {
      cerr << "Bad cast: " << e.what( ) << endl;
   }
}
