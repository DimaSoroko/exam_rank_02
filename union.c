// #include <unistd.h>

// int	main(int argc, char *argv[])
// {
// 	char	map[255];
// 	int		i;

// 	i = -1;
// 	if (argc == 3)
// 	{
// 		while (argv[1][++i])
// 		{
// 			if (map[argv[1][i]] != 1)
// 			{
// 				write(1, &argv[1][i], 1);
// 				map[argv[1][i]] = 1;
// 			}
// 		}
// 		i = -1;
// 		while (argv[2][++i])
// 		{
// 			if (map[argv[2][i]] != 1)
// 			{
// 				write(1, &argv[2][i], 1);
// 				map[argv[2][i]] = 1;
// 			}
// 		}
// 	}
// 	write(1, "\n", 1);
// }

///////////////////////////////////////////////////////////////////

// #include <unistd.h>

// void ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int	main(int ac, char **av)
// {
// 	if (ac != 3)
// 	{
// 		ft_putchar('\n');
// 		return 1;
// 	}
// 	char	hash[256] = {0};
// 	char	*s1 = av[1], *s2 = av[2];

// 	while (*s1)
// 	{
// 		if (hash[(int)*s1] == 0)
// 		{
// 			ft_putchar(*s1);
// 			hash[(int)*s1]++;
// 		}
// 		s1++;
// 	}
// 	while (*s2)
// 	{
// 		if (hash[(int)*s2] == 0)
// 		{
// 			ft_putchar(*s2);
// 			hash[(int)*s2]++;
// 		}
// 		s2++;
// 	}
// 	ft_putchar('\n');
// }

///////////////////////////////TEST/////////////////////////////

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main (int ac, char **av)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (1);
	}
	char temp[256] = {0};
	char *s1 = av[1], *s2 = av[2];
	while(*s1)
	{
		if(temp[(int)*s1] == 0)
		{
			ft_putchar(*s1);
			temp[(int)*s1]++;
		}
		s1++;
	}
	while(*s2)
	{
		if(temp[(int)*s2] == 0)
		{
			ft_putchar(*s2);
			temp[(int)*s2]++;
		}
		s2++;
	}
	ft_putchar('\n');
}