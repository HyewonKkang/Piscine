/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:54:21 by hykang            #+#    #+#             */
/*   Updated: 2021/09/29 16:04:02 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (length + 1));
	while (i < length)
	{
		tmp[i] = f(tab[i]);
		i++;
	}
	return (tmp);
}
