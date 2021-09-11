#include <unistd.h>

void	ft_putchar(char c);

void	rush(int a, int b)
{
	int	i;
	int	j;

	i = 1;
	while (i <= b)
	{
		j = 1;
		while (j <= a)
		{
			if (i == 1 || i == b || j == 1 || j == a)
			{
				if ((i == 1 && j == 1) || (i == b && j == a))
					ft_putchar('A');
				else if ((i == b && j == 1) || (i == 1 && j == a))
					ft_putchar('C');
				else
					ft_putchar('B');
			}
			else
				ft_putchar(' ');
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}
