/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:20:19 by hykang            #+#    #+#             */
/*   Updated: 2022/01/25 17:20:20 by hykang           ###   ########.fr       */
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
				print_line('A', 'B', 'A', x);
			else if (i == y - 1)
				print_line('C', 'B', 'C', x);
			else
				print_line('B', ' ', 'B', x);
			i++;
			write(1, "\n", 1);
		}
	}
}
