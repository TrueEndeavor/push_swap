#include <push_swap.h>

static int	isSign(char c)
{
	return (c == '+' || c == '-');
}

/* Checks 

- Get length of current argument
- If first character and only characer of the argument is just a sign
  return failure
- If first character is not a digit
  return failure
- If any character after the first is not a digit
  return failure (move to the next character)
*/
static int	isNotNumber(int ac, char **av)
{
	size_t	len;
	size_t	i;

	while (ac > 0)
	{
		len = ft_strlen(av[ac]);
		i = 1;
		if (isSign(av[ac][0]))
		{
			if (len == 1)
				return (1);
		}
		else if (!ft_isdigit(av[ac][0]))
			return (1);
		while (i < len)
		{
			if (!ft_isdigit(av[ac][i]))
				return (1);
			i++;
		}
		ac--;
	}
	return (0);
}
/* isDuplicate:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
/* compareIgnoringPlus:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
int	compareIgnoringPlus(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	return (ft_strcmp(s1, s2));
}

static int	isDuplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && compareIgnoringPlus(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int isOverflow(int ac, char **av)
{
	long	cmp;
	int		i;
	int		len;

	while (ac > 0)
	{
		len = ft_strlen(av[ac]);
		if (len > 11)
			return (1);
		cmp = ft_atol(av[ac]);
		if (cmp > INT_MAX || cmp < INT_MIN)
			return (1);
		i = ac - 1;
		while (i > 0)
		{
			if (cmp == ft_atol(av[i]))
				return (1);
			i--;
		}
		ac--;
	}
	return (0);
}

int isValidInput(int ac, char **av)
{
	if (ac == 1)
		exit (EXIT_SUCCESS);
	if (isNotNumber(ac - 1, av) || isOverflow(ac - 1, av) || isDuplicate(av))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
	if (ac == 2)
		exit (EXIT_SUCCESS);
	return (0);
}