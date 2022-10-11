/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:32:57 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/11 10:33:02 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
