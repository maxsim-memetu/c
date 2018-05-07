#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <regex>
#include <fstream> //have to include this for file manipulations.
using namespace std;


int main()
{
	ifstream in("trial.txt");
	if(!in)
		cerr<<"fail to open file";
	regex pat {R"([0-9]*)"};//regex has this () inside R""
	int lineno = 0;
	for(string line; getline(in, line);)
	{
		++lineno;
		smatch matches;
		if(regex_search(line, matches, pat))
		{
			cout<<lineno<<":"<<matches[0]<<endl;
			if(1<matches.size() && matches[1].matched)
			{
				cout<<"\t:"<<matches[1]<<endl;
			}
		}
	}
}	