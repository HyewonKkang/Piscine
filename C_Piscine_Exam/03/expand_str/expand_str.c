#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

void epur_str(char *str)
{
    int i;

    i = 0;
    while (str[i] && is_space(str[i]))
        i++;
    while (str[i])
    {
        if (is_space(str[i]))
        {
            if (!is_space(str[i + 1]) && str[i + 1])
                write(1, "   ", 3);
        }
        else if (!is_space(str[i]))
            write(1, &str[i], 1);
        i++;
    }
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
        epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
