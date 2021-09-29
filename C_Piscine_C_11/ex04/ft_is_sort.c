/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:54:57 by hykang            #+#    #+#             */
/*   Updated: 2021/09/29 17:37:45 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	tmp;
	int tmp_s;

	tmp_s = 0;
	while (length-- > 1)
	{
		tmp = f(tab[length], tab[length - 1]);
		if (tmp == 0)
			continue;
		if (tmp_s == 0)
			tmp_s = tmp;
		else if ((tmp_s > 0 && tmp < 0) || (tmp_s < 0 && tmp > 0))
			return (0);
	}
	return (1);
}
