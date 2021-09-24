#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int result;

    result = 0;
    while (*str)
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return (result);
}

void print_hex(int n)
{
    if (n > 15)
        print_hex(n / 16);
    n = n % 16;
    if (n < 10)
        n += '0';
    else
        n += 'a' - 10;
    ft_putchar(n);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        print_hex(ft_atoi(argv[1]));
    }
    write(1, "\n", 1);
    return (0);
}
