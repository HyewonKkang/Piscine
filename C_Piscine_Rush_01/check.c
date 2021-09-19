/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:38:10 by hykang            #+#    #+#             */
/*   Updated: 2021/09/19 20:38:10 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	count_digit(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (is_digit(*str))
			cnt++;
		str++;
	}
	return (cnt);
}

int	param_is_valid(char *str, int max_value)
{
	int	i;
	int	digit_cnt;

	i = 0;
	digit_cnt = count_digit(str);
	while (str[i])
	{
		if (i % 2 == 0)
			if (!(str[i] >= '1' && str[i] - '0' <= max_value))
				return (0);
		i++;
	}
	if (digit_cnt != (max_value * 4))
		return (0);
	return (1);
}
