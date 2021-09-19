/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:37:45 by hykang            #+#    #+#             */
/*   Updated: 2021/09/19 20:46:19 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_col_up(int **arr, int x, int max_value)
{
	int	cnt;
	int	y;
	int	highest;

	cnt = 1;
	y = 1;
	highest = arr[x][y];
	while (y <= max_value)
	{
		if (highest < arr[x][y])
		{
			highest = arr[x][y];
			cnt++;
		}
		y++;
	}
	if (cnt == arr[x][0])
		return (1);
	return (0);
}

int	check_col_down(int **arr, int x, int max_value)
{
	int	cnt;
	int	y;
	int	highest;

	cnt = 1;
	y = max_value;
	highest = arr[x][y];
	while (y >= 1)
	{
		if (highest < arr[x][y])
		{
			highest = arr[x][y];
			cnt++;
		}
		y--;
	}
	if (cnt == arr[x][max_value + 1])
		return (1);
	return (0);
}

int	check_row_left(int **arr, int y, int max_value)
{
	int	cnt;
	int	x;
	int	highest;

	cnt = 1;
	x = 1;
	highest = arr[x][y];
	while (x <= max_value)
	{
		if (highest < arr[x][y])
		{
			highest = arr[x][y];
			cnt++;
		}
		x++;
	}
	if (cnt == arr[0][y])
		return (1);
	return (0);
}

int	check_row_right(int **arr, int y, int max_value)
{
	int	cnt;
	int	x;
	int	highest;

	cnt = 1;
	x = max_value;
	highest = arr[x][y];
	while (x >= 1)
	{
		if (highest < arr[x][y])
		{
			highest = arr[x][y];
			cnt++;
		}
		x--;
	}
	if (cnt == arr[max_value + 1][y])
		return (1);
	return (0);
}

int	check_four_directions(int **arr, int max_value)
{
	int	i;

	i = 1;
	while (i <= max_value)
	{
		if (!check_col_up(arr, i, max_value))
			return (1);
		if (!check_col_down(arr, i, max_value))
			return (1);
		if (!check_row_left(arr, i, max_value))
			return (1);
		if (!check_row_right(arr, i, max_value))
			return (1);
		i++;
	}
	return (0);
}
