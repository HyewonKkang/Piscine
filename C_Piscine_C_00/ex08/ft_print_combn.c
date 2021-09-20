/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:16:07 by hykang            #+#    #+#             */
/*   Updated: 2021/09/20 17:58:04 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_cnt;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	combination(int arr[10], int index, int n, int value)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		if (g_cnt != 0)
			write(1, ", ", 2);
		while (i < index)
		{
			ft_putchar(arr[i] + '0');
			i++;
			g_cnt++;
		}
	}
	else
	{
		if (value <= 9)
		{
			arr[index] = value;
			combination(arr, index + 1, n - 1, value + 1);
			combination(arr, index, n, value + 1);
		}
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	g_cnt = 0;
	combination(arr, 0, n, 0);
}
