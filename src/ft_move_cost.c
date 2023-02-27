/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:17:06 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/27 15:56:35 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_cost(t_list **stack_a, t_list **stack_b, \
										int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		(*cost_b)++;
		(*cost_a)++;
		reverse_rotate_both(stack_a, stack_b);
	}
}

void	ft_rotate_cost(t_list **stack, int *cost, int n)
{
	while ((*cost))
	{
		if ((*cost) > 0 && n == 1)
		{
			(*cost)--;
			rotate(stack, 'a');
		}
		else if ((*cost) < 0 && n == 1)
		{
			reverse_rotate(stack, 'a');
			(*cost)++;
		}
		if ((*cost) > 0 && n == 2)
		{
			(*cost)--;
			rotate(stack, 'b');
		}
		else if ((*cost) < 0 && n == 2)
		{
			reverse_rotate(stack, 'b');
			(*cost)++;
		}
	}
}

void	ft_rotate_both(t_list **stack_a, t_list **stack_b, \
								int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate2(stack_a, stack_b);
	}
}

void	ft_move_cost(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_reverse_rotate_cost(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	ft_rotate_cost(stack_a, &cost_a, 1);
	ft_rotate_cost(stack_b, &cost_b, 2);
	push(stack_b, stack_a, 'a');
}
