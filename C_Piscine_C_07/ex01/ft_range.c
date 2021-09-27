/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:29:10 by hykang            #+#    #+#             */
/*   Updated: 2021/09/27 17:29:18 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
