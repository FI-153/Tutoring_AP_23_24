// 1.3
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* pretend 0x010000 is a hexadecimal address of code */
    long i = 0;

    /* treat this integer as a pointer, using a cast */
    long *i_ptr = (long *)i;

    /* store through this pointer --- placing bad data at address */
    (*i_ptr) = 0x000000016fdff31c;

    // printf("%ld\n",*i_ptr);

    char *p1 = NULL;                      // Null pointer
    char *p2;                             // Wild pointer: not initialized at all.
    char *p3 = malloc(10 * sizeof(char)); // Initialized pointer to allocated memory
                                          // (assuming malloc did not fail)
    free(p3);                             // p3 is now a dangling pointer, as memory has been freed
    // printf("%c\n",*p1);
    // printf("%c\n",*p2);
    // printf("%c\n",*p3);
}
