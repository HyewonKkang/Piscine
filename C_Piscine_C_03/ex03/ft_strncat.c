/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:24:28 by hykang            #+#    #+#             */
/*   Updated: 2021/09/20 20:24:45 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = dest;
	while (*dest)
		dest++;
	while (*src && i++ < nb)
		*dest++ = *src++;
	*dest++ = '\0';
	return (result);
}
