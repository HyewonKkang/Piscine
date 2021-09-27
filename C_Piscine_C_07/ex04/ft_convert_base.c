/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:30:52 by hykang            #+#    #+#             */
/*   Updated: 2021/09/27 17:56:30 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	g_i;

long long	ft_strlen(char *str);
long long	find(char *str, char c);
long long	ft_atoi_base(char *str, char *base);

int	is_op(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_base_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

void	ft_putnbr(long long nb, int radix_len, char *radix, char *arr)
{
	if (nb < 0)
	{
		nb *= -1;
		arr[g_i++] = '-';
	}
	if (nb < radix_len)
	{
		arr[g_i++] = radix[nb % radix_len];
		return ;
	}
	else
		ft_putnbr(nb / radix_len, radix_len, radix, arr);
	ft_putnbr(nb % radix_len, radix_len, radix, arr);
}

void	ft_putnbr_base(int nbr, char *base, char *arr)
{
	int	radix_len;
	int	nb;

	nb = nbr;
	radix_len = ft_strlen(base);
	ft_putnbr(nb, radix_len, base, arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*res;
	long long	conv_n;

	g_i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(nbr));
	if (!is_base_correct(base_from) || !is_base_correct(base_to))
		return (NULL);
	conv_n = ft_atoi_base(nbr, base_from);
	if (conv_n < -2147483648 || conv_n > 2147483647)
		return (NULL);
	ft_putnbr_base(conv_n, base_to, res);
	return (res);
}
