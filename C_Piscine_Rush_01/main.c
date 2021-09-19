/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:37:41 by hykang            #+#    #+#             */
/*   Updated: 2021/09/19 20:46:35 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	**arr;
	int	max_value;

	if (argc != 2)
	{
		ft_error();
		return (1);
	}
	max_value = count_digit(argv[1]) / 4;
	arr = create_table(argv[1], max_value);
	if (!param_is_valid(argv[1], max_value) || !arr)
	{
		ft_error();
		return (1);
	}
	if (resolve(arr, max_value, 1, 1))
	{
		ft_error();
		return (1);
	}
	print_table(arr, max_value);
	return (0);
}
