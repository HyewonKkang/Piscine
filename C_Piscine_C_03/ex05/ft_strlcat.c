/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:25:20 by hykang            #+#    #+#             */
/*   Updated: 2021/09/21 21:35:22 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destsize;
	unsigned int	srcsize;
	unsigned int	idx;

	destsize = ft_strlen(dest);
	srcsize = ft_strlen(src);
	idx = 0;
	while (*dest)
	{
		dest++;
		idx++;
	}
	while (*src && idx + 1 < size)
	{
		*dest++ = *src++;
		idx++;
	}
	*dest = '\0';
	if (destsize > size)
		return (srcsize + size);
	else
		return (srcsize + destsize);
}
