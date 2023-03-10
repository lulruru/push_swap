/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:24:40 by rencarna          #+#    #+#             */
/*   Updated: 2023/02/27 15:56:45 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	highest_index(t_list *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	algo3(t_list **stack_a)
{
	int	i;

	if (ft_sorted(*stack_a))
		return ;
	i = highest_index(*stack_a);
	if ((*stack_a)->index == i)
		rotate(stack_a, 'a');
	else if ((*stack_a)->next->index == i)
		reverse_rotate(stack_a, 'a');
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a, 'a');
}
