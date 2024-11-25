// 2.4
#include <stdio.h>

int main()
{
    int x = 3;
    int *y = &x; // y punta alla cella di x
    *y = *y + 1;
    printf("x becomes: %d\n", x);
    printf("and since y was pointing to x it is: %d", *y);
    return 0;
}
