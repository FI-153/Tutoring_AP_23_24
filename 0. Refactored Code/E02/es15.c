// 4.2
#include <stdio.h>
#include <string.h>

int main()
{
   int age;
   char name[10];
   char surname[10];

   // AAAAAAAAAAAAAAAAAAAA and you are 1 years old.
   printf("%p\n", &age);
   printf("Enter your age: ");
   scanf("%d", &age);

   printf("%p\n", &name);
   printf("%p\n", &name[0]);
   printf("%p\n", &name[1]);
   printf("%p\n", &name[2]);
   printf("%p\n", &name[3]);
   printf("%p\n", &name[4]);
   printf("%p\n", &name[5]);
   printf("%p\n", &name[6]);
   printf("%p\n", &name[7]);
   printf("%p\n", &name[8]);
   printf("%p\n", &name[9]);
   printf("%p\n", &name[10]);
   printf("%p\n", &name[11]);

   printf("Enter your name: ");

   scanf("%s", &name);

   printf("%p\n", &surname);
   printf("%p\n", &surname[0]);
   printf("%p\n", &surname[1]);
   printf("%p\n", &surname[2]);
   printf("%p\n", &surname[3]);
   printf("%p\n", &surname[4]);
   printf("%p\n", &surname[5]);
   printf("%p\n", &surname[6]);
   printf("%p\n", &surname[7]);
   printf("%p\n", &surname[8]);
   printf("%p\n", &surname[9]);
   printf("%p\n", &surname[10]);
   printf("%p\n", &surname[11]);

   printf("Enter your surname: ");

   scanf("%s", &surname);

   printf("Your name is %s and surname %s you are %d years old.\n", name, surname, age);

   return 0;
}
