/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:41:28 by hykang            #+#    #+#             */
/*   Updated: 2021/09/25 10:01:15 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_op(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	negative;
	int	minus_cnt;
	int	i;
	int	result;

	negative = 1;
	minus_cnt = 0;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && is_op(str[i]))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] && is_digit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (negative * result);
}
