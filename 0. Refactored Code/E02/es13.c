// 3.2
#include <stdio.h>

int mystrlen(const char *s)
{
	if (!s)
		return 0;

	int i;
	for (i = 0; s[i] != 0; i++)
		;

	return i;
}

int main()
{
	int l;
	char s[10] = "pippo";
	printf("la stringa %s è lunga %d\n", s, mystrlen(s));

	char s2[3];
	s2[0] = 'A';
	s2[1] = 'B';
	s2[2] = 'C';
	printf("la stringa %s è lunga %d\n", s2, mystrlen(s2));
}
