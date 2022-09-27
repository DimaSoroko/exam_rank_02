// #include <stdio.h>
// #include <unistd.h>

// int	main(int argc, char *argv[])
// {
// 	char	map[255];
// 	int		i;
// 	int		j;

// 	i = -1;
// 	if (argc == 3)
// 	{
// 		while (argv[1][++i])
// 		{
// 			j = -1;
// 			while (argv[2][++j])
// 			{
// 				if (map[argv[1][i]] != 1 && (argv[1][i] == argv[2][j]))
// 				{
// 					write(1, &argv[1][i], 1);
// 					map[argv[1][i]] = 1;
// 				}
// 			}
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

//////////////////////////////////////////////////////////////////////////////////////

// #include <unistd.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int	main(int ac, char **av)
// {
// 	if (ac != 3)
// 	{
// 		ft_putchar('\n');
// 		return (0);
// 	}
// 	char	hash[256] = {0};
// 	char	*s1 = av[1], *s2 = av[2];

// 	while (*s2)
// 	{
// 		hash[(int)*s2] = 1;
// 		s2++;
// 	}
// 	while (*s1)
// 	{
// 		if (hash[(int)*s1] == 1)
// 		{
// 			ft_putchar(*s1);
// 			hash[(int)*s1] = 0;
// 		}
// 		s1++;
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
		return 0;
	}
	char temp[256] = {0};
	char *s1 = av[1], *s2 = av[2];
	while(*s2)
	{
		temp[(int)*s2] = 1;
		s2++;
	}
	while(*s1)
	{
		if(temp[(int)*s1] == 1)
		{
			ft_putchar(*s1);
			temp[(int)*s1] = 0;
		}
		s1++;
	}
	ft_putchar('\n');
}