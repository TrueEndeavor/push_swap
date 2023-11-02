#include <push_swap.h>

int main(int ac, char **av)
{
	t_push_swap_data	*data;
	if (isValidInput(ac, av))
		return (1);
	dprintf(1,"hello");
	data = initialize_push_swap_data(ac, av);
	print_push_swap_data(data);

	return (0);
}