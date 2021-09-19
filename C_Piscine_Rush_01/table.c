/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:09:46 by hykang            #+#    #+#             */
/*   Updated: 2021/09/19 23:09:47 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	*create_params_table(char *params, int max_value)
{
	int	*tmp;
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	tmp = (int *)malloc(sizeof(int) * max_value * max_value);
	while (params[cnt] && i < max_value * max_value)
	{
		tmp[i] = params[cnt] - '0';
		cnt += 2;
		i++;
	}
	return (tmp);
}

void	fill_edge_of_table(int **arr, int *tmp, int max_value)
{
	int	i;

	i = 0;
	while (++i <= max_value)
	{
		arr[0][i] = tmp[i - 1];
	}
	i = 0;
	while (++i <= max_value)
	{
		arr[max_value + 1][i] = tmp[i + 3];
	}
	i = 0;
	while (++i <= max_value)
	{
		arr[i][0] = tmp[i + 7];
	}
	i = 0;
	while (++i <= max_value)
	{
		arr[i][max_value + 1] = tmp[i + 11];
	}
}

void	fill_table(int **arr, int max_value, char *params)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = create_params_table(params, max_value);
	while (i < max_value + 2)
	{
		j = 0;
		while (j++ < max_value + 2)
			arr[i++][j] = 0;
	}
	fill_edge_of_table(arr, tmp, max_value);
}

int	**create_table(char *params, int max_value)
{
	int	i;
	int	j;
	int	**arr;

	arr = (int **)malloc(sizeof(int *) * max_value + 2);
	if (!(arr))
		return (0);
	i = -1;
	while (++i < max_value + 2)
	{
		arr[i] = (int *)malloc(sizeof(int) * max_value + 2);
		if (!(arr[i]))
			return (0);
	}
	i = -1;
	while (++i < max_value + 2)
	{
		j = 0;
		while (j < max_value + 2)
		{
			arr[i][j++] = 0;
		}
	}
	fill_table(arr, max_value, params);
	return (arr);
}

void	print_table(int **arr, int max_value)
{
	int	i;
	int	j;

	i = 1;
	while (i <= max_value)
	{
		j = 1;
		while (j <= max_value)
		{
			ft_putchar(arr[i][j] + '0');
			if (j != max_value)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
