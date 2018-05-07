#include <iostream>
#include <fstream>
const static int BUFSIZE=4096;

using std::ios_base;
int main(int argc, char** argv) {
	//in CPP, io( like console and other devices) are modeled as stream, this is different to C which model io as char string/array.
	//In CPP, we have iostream which mainly deal with console input output, fstream, which deals with file input/output, models file
	// io as stream, 
	std::ifstream in(argv[1], ios_base::in | ios_base::binary);
	std::ofstream out(argv[2], ios_base::out | ios_base::binary);

	char buf[BUFSIZE]; //triple buffering, because ifstream and ofstream both have buffer
	do{
		in.read(&buf[0], BUFSIZE);
		out.write(&buf[0], in.gcount());
	} while(in.gcount() > 0);
	in.close();
	out.close();
}