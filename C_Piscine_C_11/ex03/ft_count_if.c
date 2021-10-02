/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:54:48 by hykang            #+#    #+#             */
/*   Updated: 2021/09/29 16:02:53 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	cnt;

	cnt = 0;
	while (length--)
	{
		if (f(*tab) != 0)
			cnt++;
		tab++;
	}
	return (cnt);
}