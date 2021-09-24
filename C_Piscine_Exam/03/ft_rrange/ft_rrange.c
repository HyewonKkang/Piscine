#include <stdlib.h>

int ft_abs(int n)
{
    if (n >= 0)
        return (n);
    else
        return (-n);
}

int *ft_rrange(int start, int end)
{
    int i;
    int *arr;

    i = 0;
    arr = (int *)malloc(sizeof(int) * (ft_abs(start - end) + 1));
    while (start < end)
    {
        arr[i] = end--;
        i++;
    }
    arr[i] = end;
    while (start > end)
    {
        arr[i] = end++;
        i++;
    }
    arr[i] = end;
    return (arr);
}
