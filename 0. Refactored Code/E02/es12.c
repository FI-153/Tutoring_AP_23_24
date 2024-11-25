// 3.1
#include <stdio.h>

// conta quanti sono i pari
int contapari(const int *s, int n)
{
    if (!s) // NULL CHECK
        return 0;
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        if (*(s + i) % 2 == 0)
            result++;

        // Alternative
        //  if (s[i] % 2 == 0)
        //      result++;
    }
    return result;
}

int main(void)
{
    int s[4] = {1, 2, 3, 4};

    int l = contapari(s, 4);
    printf("i pari sono %d\n", l);

    // Going outside the bounds of our array (we didn't use malloc)
    l = contapari(s, 40);
    printf("i pari sono %d\n", l);
}
