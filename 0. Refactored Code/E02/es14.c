// 4.1
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff);

    // give thegeekstuff
    if (strcmp(buff, "thegeekstuff\n"))
    {
        printf("\n Wrong Password \n");
    }
    else
    {
        printf("\n Correct Password \n");
        pass = 1;
    }

    if (pass)
    {
        /* Now Give root or admin rights to user*/
        printf("\n Root privileges given to the user \n");
    }

    return 0;
}
