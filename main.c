/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/02 14:14:26 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int issort(int ac, char **av)
{
	int	i;
	int	j;
	int tmp;

	i = 1;
	while(i < ac)
	{
		j = i + 1;
		if (ft_atol(av[i]) < ft_atol(av[j]))
		{
			tmp++;	
		}
		i++;
	}
	printf("%d", tmp);
	return (tmp);
}

int main(int ac, char **av)
{
	int	i = issort(ac,av);
	printf("%d", i);
}