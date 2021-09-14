#include <unistd.h>

void    ft_ultimate_div_mod(int *a, int *b)
{
    int d;
    int m;

    d = *a / *b;
    m = *a % *b;

    *a = d;
    *b = m;
}