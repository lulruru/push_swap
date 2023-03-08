/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:45:47 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/08 16:17:11 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
push3 est une fonction qui permet de push tout les elemnts
de la stack a sauf les trois derniers. les elements les en dessous
de la median sont push en premier ensuite on push le reste jusqua 
quil en reste que trois.
*/
void	push3(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int	pushed;

	size = lstsize(*stack_a);
	i = 0;
	pushed = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			push(stack_a, stack_b, 'b');
			pushed++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	while (size - pushed > 3)
	{
		push(stack_a, stack_b, 'b');
		pushed++;
	}
}

/* Fonction qui remet de dans l'ordre les elements */
void	ft_tri_a(t_list **stack_a)
{
	int	low;
	int	size;

	low = ft_lowest_index_pos(stack_a);
	size = lstsize(*stack_a);
	if (low > size / 2)
	{
		while (low < size)
		{
			reverse_rotate(stack_a, 'a');
			low++;
		}
	}
	else
		while (low-- > 0)
			rotate(stack_a, 'a');
}

/* 
FILE :
	ft_target_best_pos = indexer.c
	ft_cost / ft_less_possible_move  = ft_cost.c
*/
void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	push3(stack_a, stack_b);
	algo3(stack_a);
	while (*stack_b)
	{
		ft_target_best_pos(stack_a, stack_b);
		ft_cost(stack_a, stack_b);
		ft_less_possible_move(stack_a, stack_b);
	}
	if (!ft_sorted(*stack_a))
		ft_tri_a(stack_a);
}
