/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:57:18 by hykang            #+#    #+#             */
/*   Updated: 2021/09/27 17:59:40 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sep(char *str, char *charset)
{
	int	idx;

	idx = 0;
	while (charset[idx])
	{
		if (! *str)
			return (0);
		if (*str++ != charset[idx])
			return (0);
		idx++;
	}
	return (1);
}

int	count_words(char *str, char *charset)
{
	int	cnt;
	int	i;

	cnt = 0;
	while (*str)
	{
		while (*str && is_sep(str, charset))
		{
			i = 0;
			while (i++ < ft_strlen(charset))
				str++;
		}
		if (*str && !is_sep(str, charset))
		{
			cnt++;
			while (*str && !is_sep(str, charset))
				str++;
		}
	}
	return (cnt);
}

char	*malloc_word(char *str, char *charset)
{
	char	*word;
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (*tmp && !is_sep(str, charset))
	{
		i++;
		tmp++;
	}
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str && !is_sep(str, charset))
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		cnt;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && is_sep(str, charset))
		{
			cnt = 0;
			while (cnt++ < ft_strlen(charset))
				str++;
		}
		if (*str && !is_sep(str, charset))
		{
			res[i++] = malloc_word(str, charset);
			while (*str && !is_sep(str, charset))
				str++;
		}
	}
	res[i] = 0;
	return (res);
}
