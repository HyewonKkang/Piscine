/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:21:48 by hykang            #+#    #+#             */
/*   Updated: 2021/09/15 10:24:05 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp >= 'A' && *temp <= 'Z')
			*temp += 32;
		temp++;
	}
	return (str);
}

int	ft_str_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_str_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_first_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (ft_str_is_first_letter(str[i]))
				str[i] -= 32;
		}
		else if (!ft_str_is_alpha(str[i - 1]) && !ft_str_is_numeric(str[i - 1]))
		{
			if (ft_str_is_first_letter(str[i]))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
