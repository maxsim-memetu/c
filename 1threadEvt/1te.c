#include <stdio.h>

int main(){
	enum states
	{
		s1,
		s2,
		s3
	};
	int s=s1;
	for(;;){
		switch(s){
			case s1:
				printf("to state 2\n");
				s=s2;
				break;
			case s2:
				printf("to state 3\n");
				s=s3;
				break;
			case s3:
				printf("to end\n");
				goto END;
		}
	}
END:
	return 0;
}