#include <stdio.h>
#include <stdlib.h>

int get_gcd(unsigned int n1, unsigned int n2)
{
    int i;

    i = n1;
    while (i > 0)
    {
        if (n1 % i == 0 && n2 % i == 0)
            return (i);
        i--;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("%d", get_gcd(atoi(argv[1]), atoi(argv[2])));
    }
    printf("\n");
    return (0);
}
