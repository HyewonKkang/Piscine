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

void	ft_putnbr(int nb, int radix_len, char *radix)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb < radix_len)
	{
		ft_putchar(radix[nb % radix_len]);
		return ;
	}
	else
		ft_putnbr(nb / radix_len, radix_len, radix);
	ft_putnbr(nb % radix_len, radix_len, radix);
}


void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int radix_len;
    unsigned int nb;

    nb = nbr;
    if (!is_base_correct(base))
        return ;
    radix_len = ft_strlen(base);
    ft_putnbr(nb, radix_len, base);
}
