#include <unistd.h>

int is_lowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_lowstr(char *str)
{
    int i;

    i = 0;
    int len;

    len = 0;
    while(str[len])
        len++;
    while (i < len)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}

int main(int argc, char *argv[])
{
    int i;
    int argc_idx;
    char *str;

    argc_idx = 1;
    if (argc >= 2)
    {
        while (argc_idx < argc)
        {
            i = 0;
            str = ft_lowstr(argv[argc_idx]);
            while (argv[argc_idx][i])
            {
                if (i == 0 && is_lowercase(str[i]))
                    ft_putchar(argv[argc_idx][i] - 32);
                else if (is_lowercase(str[i]) && is_space(str[i-1]))
                    ft_putchar(argv[argc_idx][i] - 32);
                else
                    ft_putchar(argv[argc_idx][i]);
                i++;
            }
            ft_putchar('\n');
            argc_idx++;
        }
    }
    return (0);
}
