/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:30:01 by hykang            #+#    #+#             */
/*   Updated: 2021/09/28 17:50:24 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*malloc_str(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*arr;

	len = ft_strlen(sep) * (size - 1);
	i = 0;
	while (strs[i])
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	return (arr);
}

char	*ft_strcat(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*tmp;
	int		i;

	if (!size)
	{
		res = (char*)malloc(1);
		res[0] = 0;
		return (res);
	}
	res = malloc_str(size, strs, sep);
	tmp = ft_strcat(res, strs[0]);
	i = 0;
	while (i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i++]);
	}
	*tmp = 0;
	return (res);
}
