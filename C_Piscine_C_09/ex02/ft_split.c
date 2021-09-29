/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:57:18 by hykang            #+#    #+#             */
/*   Updated: 2021/09/29 09:07:26 by hykang           ###   ########.fr       */
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

int	is_sep(char c, char *charset)
{
	int	idx;

	idx = 0;
	while (charset[idx])
	{
		if (c == charset[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			cnt++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (cnt);
}

char	*malloc_word(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			res[i++] = malloc_word(str, charset);
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	res[i] = 0;
	return (res);
}
