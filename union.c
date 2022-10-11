/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:32:22 by dsoroko           #+#    #+#             */
/*   Updated: 2022/10/11 10:32:43 by dsoroko          ###   ########.fr       */
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
