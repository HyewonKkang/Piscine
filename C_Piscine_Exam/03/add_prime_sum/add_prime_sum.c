#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + '0');
}

int ft_atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

int is_prime(int n)
{
    int i;

    i = 2;
    while (i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int get_sum_of_prime(int n)
{
    int i;
    int sum;

    i = 2;
    sum = 0;
    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    return (sum);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        ft_putnbr(get_sum_of_prime(ft_atoi(argv[1])));
    }
    else
        write(1, "0", 1);
    write(1, "\n", 1);
    return (0);
}
