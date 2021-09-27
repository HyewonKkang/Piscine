/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:56:42 by hykang            #+#    #+#             */
/*   Updated: 2021/09/27 17:57:05 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	find(char *str, char c)
{
	long long	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi_base(char *str, char *base)
{
	long long	negative;
	long long	i;
	long long	result;
	long long	index;

	negative = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	index = find(base, str[i]);
	while (str[i] && index >= 0)
	{
		result = result * ft_strlen(base) + index;
		index = find(base, str[++i]);
	}
	return (result * negative);
}
