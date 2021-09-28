/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:30:52 by hykang            #+#    #+#             */
/*   Updated: 2021/09/28 17:08:09 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	find(char *str, char c);
int	ft_atoi_base(char *str, char *base);

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

int	nbr_size(long long nbr, int base_len)
{
	int res_size;

	if (!nbr)
		return (1);
	res_size = 0;
	if (nbr < 0)
		++res_size;
	while (nbr)
	{
		nbr /= base_len;
		++res_size;
	}
	return (res_size);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	tmp;
	char		*ret;
	int			size;

	if (nbr == 0)
	{
		ret = (char*)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_size(tmp, ft_strlen(base));
	ret = (char*)malloc(sizeof(char) * (size + 1));
	ret[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % ft_strlen(base)];
		tmp /= ft_strlen(base);
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*res;
	int	conv_n;

	if (!is_base_correct(base_from) || !is_base_correct(base_to))
		return (NULL);
	conv_n = ft_atoi_base(nbr, base_from);
	res = ft_putnbr_base(conv_n, base_to);
	return (res);
}
