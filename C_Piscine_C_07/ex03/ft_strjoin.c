/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:30:01 by hykang            #+#    #+#             */
/*   Updated: 2021/09/27 20:49:46 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*malloc_str(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*arr;

	if (size == 0)
	{
		*arr = '\0';
		return (arr);
	}
	len = ft_strlen(sep) * (size - 1);
	i = 0;
	while (strs[i])
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	arr = (char *)malloc(sizeof(char) * len);
	return (arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		j;
	int		k;
	int		idx;

	idx = 0;
	i = 0;
	res = malloc_str(size, strs, sep);
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			res[idx++] = strs[i][j++];
		k = 0;
		while (sep[k] && i != size - 1)
			res[idx++] = sep[k++];
		i++;
	}
	return (res);
}
