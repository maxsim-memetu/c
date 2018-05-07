#include <stdio.h>
//#include "1.h"
void f(void)
{
	printf("in f\n");
}
int main()
{
	void (*pf)(void);
	pf = &f;
	(*pf)();
	pf();
	return 0;
}
