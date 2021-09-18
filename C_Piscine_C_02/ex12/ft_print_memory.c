/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:04:41 by hykang            #+#    #+#             */
/*   Updated: 2021/09/18 17:05:03 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	addr_hex(unsigned long long addr, unsigned int cnt)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr != 0)
	{
		addr_hex(addr / 16, cnt + 1);
		write(1, &hex[addr % 16], 1);
	}
	else
	{
		while (cnt++ < 16)
			write(1, "0", 1);
	}
}

void	print_hex(char *str)
{
	 int	cnt;
	char	*hex;

	cnt = 0;
	hex = "0123456789abcdef";
	while (cnt < 16)
	{
		if (!*str)
		{
			write(1, " ", 1);
			break ;
		}
		write(1, &hex[*str / 16], 1);
		write(1, &hex[*str % 16], 1);
		if (cnt % 2 == 1)
			write(1, " ", 1);
		str++;
		cnt++;
	}
	while (cnt++ < 16)
	{
		if (cnt % 2 == 1)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
}

void	print_str(char *str)
{
	int	cnt;

	cnt = 0;
	while (cnt < 16)
	{
		if (!*str)
			break ;
		if (*str <= 31 || *str >= 127)
		{
			write(1, ".", 1);
		}
		else
			write(1, str, 1);
		str++;
		cnt++;
	}
	write(1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	        char	*tmp;

	tmp = (char *)addr;
	i = 0;
	if (size == 0)
		return ;
	while (*tmp && i < size)
	{
		addr_hex((unsigned long long)tmp, 0);
		write(1, ": ", 2);
		print_hex(tmp);
		print_str(tmp);
		tmp += 16;
		i += 16;
	}
}
