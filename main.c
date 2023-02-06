/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/06 17:09:03 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* p_list *createliste(int ac, char **av)
{
	p_list *new;
	p_list *Data;
	int	i = 1;
	new = malloc(sizeof(p_list));
	while (i < ac)
	{
		Data->data = atoi(av[i]);
		Data->next = NULL;
		addback(&new, Data);
		i++;
	}
	new->next = NULL;
	return (new);
} */
void formatcheck(int ac, char **av)
{
	if (ac == 2)
	{
		
	}
}

int main(int ac, char **av)
{
	p_list	*pile_a;
	p_list	*pile_b;
	int		i;

	i = 1;
	if (ft_pars(ac, av))
	{
		printf("error");
	}
	else 
	{
		pile_b = NULL;
		pile_a = do_list(ac, av);
		while (pile_a)
		{
			printf("%d ", pile_a->data);
			pile_a = pile_a->next;
		}
		printf("\n");
		algo3 (pile_a);
		while (pile_a)
		{
			printf("%d ", pile_a->data);
			pile_a = pile_a->next;
		}
	}
	return (0);
}