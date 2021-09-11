#include <unistd.h>

void	ft_putchar(char c);

void	rush(int a, int b)
{
	int	i;
	int j;

	i = 1;
	while (i <= b)
	{
		j = 1;
		while (j <= a)
		{
			if (i == 1 || i == b || j == 1 || j == a)
			{
				if ((i == 1 || i == b) && (j != 1 && j != a))
					ft_putchar('-');
				else if ((j == 1 || j == a) && (i != 1 && i != b))
					ft_putchar('|');
				else
					ft_putchar('o');
			}
			else
				ft_putchar(' ');
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}
