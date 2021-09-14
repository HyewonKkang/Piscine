#include <unistd.h>

void    ft_rev_int_tab(int *tab, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = size - 1;
    while (i <= j)
    {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
        i++;
        j--;
    }
}