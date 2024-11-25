// 1.2
#include <stdio.h>
#include <stdlib.h>

int *foo(int y)
{
	int *h = malloc(sizeof(int));
	// devo fare la free altrimenti la memoria rimane allocata.
	// free(h);
	*h = y;
	return h;
}

int main(void)
{
	int *p = foo(3);
	printf("%d\n", *p);
	return 0;
}
