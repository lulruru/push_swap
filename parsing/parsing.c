/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:44:14 by russelenc         #+#    #+#             */
/*   Updated: 2023/01/27 11:45:47 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_num(char c)
{
	if (c <= '0' && c >= '9')
		return(1);
	return (0);
}

int	ft_pars(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!is_num(av[i][j]))
			return (1);
		j = i + 1;
		while(j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}




int main(int ac, char **av)
{
	int	i;
	
	if (ac > 2)
	{
		if (ft_pars(ac,av) == 1)
			printf("ERROR");
	}
	printf("\n");
}