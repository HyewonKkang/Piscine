/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:32:59 by hykang            #+#    #+#             */
/*   Updated: 2021/09/18 13:35:36 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	 int	negative;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (*str <= 31 || *str >= 127)
		{
			write(1, "\\", 1);
			if (*str < 0)
			{
				negative = (-128 - (*str)) * -1 + 128;
				write(1, &hex[negative / 16], 1);
				write(1, &hex[negative % 16], 1);
			}
			else
			{
				write(1, &hex[*str / 16], 1);
				write(1, &hex[*str % 16], 1);
			}
		}
		else
			write(1, str, 1);
		str++;
	}
}
