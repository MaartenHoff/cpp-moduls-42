#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char c;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			c = argv[j][i];
			if (islower(argv[j][i]))
				c -= 'a' - 'A';
			std::cout << c;
			i++;
		}
		j++;
	}
	std::cout << "\n";
	return (0);
}