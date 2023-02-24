/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:45:47 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/21 18:08:07 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/*
push3 est une fonction qui permet de push tout les elemnts
de la stack a sauf les trois derniers. les elements les en dessous
de la median sont push en premier ensuite on push le reste jusqua 
quil en reste que trois.
*/
void push3(p_list **stack_a,p_list **stack_b)
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
			push(stack_a,stack_b, 'b');
			pushed++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	while ( size - pushed > 3)
	{
		push(stack_a,stack_b, 'b');
		pushed++;
	}
	printf("============\n");
	printf("stack_a : ");
	printdta(*stack_a);
	printf("stack_b : ");
	printdta(*stack_b);
	printf("============\n");
}

void ft_tri_a(p_list **stack_a)
{
	int low;
	int size;

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
		while(low > 0)
		{
			rotate(stack_a, 'a');
			low--;
		}
}

void ft_sort(p_list **stack_a, p_list **stack_b)
{
	push3(stack_a,stack_b);
	algo3(stack_a);\
	printf("=====AFTER TRI=====\n");
	printf("stack_a : ");
	printdta(*stack_a);
	printf("stack_b : ");
	printdta(*stack_b);
	printf("============\n");
 	while (*stack_b)
	{
		ft_target_best_pos(stack_a, stack_b);
		ft_cost(stack_a, stack_b);
		ft_less_possible_move(stack_a,stack_b);
		printf("============\n");
		printf("stack_a : ");
		printdta(*stack_a);
		printf("stack_b : ");
		printdta(*stack_b);
		printf("============\n");
	}
	if (!ft_sorted(*stack_a))
		ft_tri_a(stack_a);
}