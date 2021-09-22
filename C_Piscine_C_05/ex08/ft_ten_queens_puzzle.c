/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:32:27 by hykang            #+#    #+#             */
/*   Updated: 2021/09/23 00:35:20 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_cnt;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_queen_case(int arr[10])
{
	int	i;

	i = 0;
	while (i < 10)
		ft_putchar(arr[i++] + '0');
	ft_putchar('\n');
}

int	can_set_queen(int arr[10], int cur_row)
{
	int	i;

	i = 0;
	while (i < cur_row)
	{
		if (arr[i] == arr[cur_row] || (cur_row - i) == (arr[i] - arr[cur_row]))
			return (0);
		else if ((cur_row - i) == (arr[cur_row] - arr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	set_queens(int arr[10], int row)
{
	int	i;
	int	cnt;

	cnt = 0;
	if (row == 10)
	{
		g_cnt++;
		print_queen_case(arr);
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			arr[row] = i;
			if (can_set_queen(arr, row))
				set_queens(arr, row + 1);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;

	i = 0;
	g_cnt = 0;
	set_queens(arr, 0);
	return (g_cnt);
}
