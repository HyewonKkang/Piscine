/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:01:34 by gyepark           #+#    #+#             */
/*   Updated: 2021/09/11 19:01:58 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c);

void	print_line(char start, char middle, char end, int column_count)
{
	ft_putchar(start);
	while (--column_count > 1)
		ft_putchar(middle);
	if (column_count)
		ft_putchar(end);
}

void	rush(int x, int y)
{
	int	i;

	if (x > 0 && y > 0)
	{
		i = 0;
		while (i < y)
		{
			if (i == 0)
				print_line('o', '-', 'o', x);
			else if (i == y - 1)
				print_line('o', '-', 'o', x);
			else
				print_line('|', ' ', '|', x);
			i++;
			write(1, "\n", 1);
		}
	}
}
