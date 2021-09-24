#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int main(int argc, char *argv[])
{
    argv = 0;
    ft_putnbr(argc - 1);
    return (0);
}
