#include <stdio.h>
#include <string.h>

int main()
{
  int age;
  char name[4];
  char surname[4];

  printf("puntatore name: %p\n", &name);
  printf("puntatore age: %p\n", &age);
  scanf("%d", &age);
  scanf("%s", &name);

  printf("Your name is %s and you are %d years", name, age);
}
