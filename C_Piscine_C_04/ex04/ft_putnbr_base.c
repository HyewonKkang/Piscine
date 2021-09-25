/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:41:51 by hykang            #+#    #+#             */
/*   Updated: 2021/09/25 10:01:11 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_op(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (is_op(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (i != j && base[i] == base[j++])
				return (0);
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	radix_len;
	unsigned int	nb;

	nb = (unsigned int)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = (unsigned int)(-1 * nbr);
	}
	if (!is_base_correct(base))
		return ;
	radix_len = ft_strlen(base);
	if (nb >= radix_len)
	{
		ft_putnbr_base(nb / radix_len, base);
		ft_putnbr_base(nb % radix_len, base);
	}
	else
		write(1, &base[nb], 1);
}
