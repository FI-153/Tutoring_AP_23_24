// 1.1
#include <stdio.h>

int *foo(int y)
{
	int h = y;
	int *p = &h;
	return p;
}
// ritorno un puntatore ad un area dello stack che poi viene deallocata.
// 1pt bonus come faccio a scrivere dentro la cella puntata da p?

int main(void)
{
	int *p = foo(3);
	printf("%d\n", *p);

	// ptbonus
	foo(4);
	printf("%d\n", *p);
}
