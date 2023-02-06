/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:24:40 by rencarna          #+#    #+#             */
/*   Updated: 2023/02/06 17:06:12 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(p_list **stack)
{
	while (*stack)
	{
		printf("%d", (*stack)->data);
		*stack = (*stack)->next;
	}
}

void	algo3(p_list **stack_a)
{
	p_list	**stack_b;

	stack_b = 0;
	push(stack_a, stack_b, 'b');
	print_stack(stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		swap(stack_a, 'a');
	}
	push(stack_a, stack_b, 'a');
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		swap(stack_a, 'a');
	}
	else
		rotate(stack_a, 'a');
}
