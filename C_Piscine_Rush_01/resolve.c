/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:37:49 by hykang            #+#    #+#             */
/*   Updated: 2021/09/19 20:37:50 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	g_max;

int	check(int **arr, int i, int x, int y)
{
	int	row;
	int	column;

	row = 1;
	column = 1;
	while (row <= g_max)
	{
		if (i == arr[row][y])
			return (1);
		row++;
	}
	while (column <= g_max)
	{
		if (i == arr[x][column])
			return (1);
		column++;
	}
	return (0);
}

int	recursive_check(int **arr, int max_value, int x, int y)
{
	if (x == max_value)
	{
		if (resolve(arr, max_value, 1, y + 1))
			return (1);
		return (0);
	}
	else
	{
		if (resolve(arr, max_value, x + 1, y))
			return (1);
		return (0);
	}
}

int	cmp_check(int **arr, int i, int x, int y)
{
	if (i <= g_max)
		arr[x][y] = i;
	else
	{
		arr[x][y] = 0;
		return (1);
	}
	return (0);
}

int	resolve(int **arr, int max_value, int x, int y)
{
	int	i;

	i = 1;
	g_max = max_value;
	while (1)
	{
		while (i <= max_value && check(arr, i, x, y))
			i++;
		if (cmp_check(arr, i, x, y))
			return (1);
		if (x == max_value && y == max_value)
		{
			if (check_four_directions(arr, max_value))
			{
				if (cmp_check(arr, i, x, y))
					return (1);
				continue ;
			}
			else
				return (0);
		}
		if (recursive_check(arr, max_value, x, y))
			continue ;
		return (0);
	}
}
