/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/07 16:38:03 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push_swap(p_list **stack_a, int size)
{
	if (size == 2 && !ft_sorted(*stack_a))
		swap(stack_a, 'a');
	if (size == 3)
		algo3(stack_a);
}
void printdta(p_list *stacka)
{
	while (stacka)
	{
		printf("%d ", stacka->data);
		stacka = stacka->next;	
	}
	printf("\n");
}
int main(int ac, char **av)
{
	p_list	*stack_a;
/* 	p_list	*stack_b; */
	int		size;
	
	if (ac < 2)
		return(0);
	if (ft_pars(ac, av))
		ft_error(NULL, NULL);
	// stack_b = NULL;
	stack_a = do_list(ac, av);
	size = lstsize(stack_a);
	printdta(stack_a);
	indexer(stack_a, size + 1);
	push_swap(&stack_a, size);
}
