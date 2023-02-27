/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/27 16:32:32 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2 && !ft_sorted(*stack_a))
		swap(stack_a, 'a');
	if (size == 3)
		algo3(stack_a);
	if (size > 3)
		ft_sort(stack_a, stack_b);
}

/* void printdta(t_list *stacka)
{
	while (stacka)
	{
		printf("%d ", stacka->data);
		stacka = stacka->next;	
	}
	printf("\n");
} */

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	if (ft_pars(ac, av))
		ft_error(NULL, NULL);
	stack_b = NULL;
	stack_a = do_list(ac, av);
	size = lstsize(stack_a);
	ft_indexer(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	if (ft_sorted(stack_a))
		printf("NICE");
	ft_free(&stack_a);
	ft_free(&stack_b);
}
