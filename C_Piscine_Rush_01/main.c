#include "rush.h"

int	main(int argc, char *argv[])
{
	int	**arr;
	int	max_value;

	if (argc != 2)
	{
		ft_error();
		return (1);
	}
	max_value = count_digit(argv[1]) / 4;
	if (!param_is_valid(argv[1], max_value))
	{
		ft_error();
		return (1);
	}
	arr = create_table(argv[1], max_value);
	if (!arr || resolve(arr, max_value, 1, 1))
	{
		ft_error();
		return (1);
	}
	print_table(arr, max_value);
	return (0);
}
