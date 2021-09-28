#include <unistd.h>

int is_op(char c)
{
    if (c == '+' || c == '-')
        return (1);
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_base_correct(char *base)
{
    int i;
    int j;

    i = 0;

    while (base[i])
    {
        if (is_op(base[i]))
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (i != j && base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    if (i < 2)
        return (0);
    return (1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int radix_len;
    unsigned int nb;

    if (!is_base_correct(base))
        return ;
    radix_len = ft_strlen(base);
    if (nbr < 0)
	{
		ft_putchar('-');
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= radix_len)
	{
		ft_putnbr_base(nb / radix_len, base);
		ft_putchar(base[nb % radix_len]);
	}
	else
		ft_putchar(base[nb % radix_len]);
}
