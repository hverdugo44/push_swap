#include "libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
