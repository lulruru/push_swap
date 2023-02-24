/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/21 17:56:55 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push_swap(p_list **stack_a, p_list **stack_b, int size)
{
	if (size == 2 && !ft_sorted(*stack_a))
		swap(stack_a, 'a');
	if (size == 3)
		algo3(stack_a);
	if (size > 5)
		ft_sort(stack_a, stack_b);
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
	p_list	*stack_b;
	p_list *tmp;
	int		size;
	
	if (ac < 2)
		return(0);
	if (ft_pars(ac, av))
		ft_error(NULL, NULL);
	stack_b = NULL;
	stack_a = do_list(ac, av);
	size = lstsize(stack_a);
	printdta(stack_a);
	ft_indexer(stack_a, size + 1);
	tmp = stack_a;//a suppriner
	while (tmp)
	{
		printf("======================\n");
		printf("tmp->index %d\n", tmp->index);
		printf("tmp->data %d\n", tmp->data);
		printf("======================\n");
		tmp = tmp->next;
	}//a supprimer
	push_swap(&stack_a, &stack_b, size);
	printdta(stack_a);
	ft_free(&stack_a);
	ft_free(&stack_b);
}
