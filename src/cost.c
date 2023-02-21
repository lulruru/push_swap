/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:08:53 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/18 19:35:07 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_cost(p_list **stack_a, p_list **stack_b)
{
	p_list *tmp_a;
	p_list *tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = lstsize(tmp_a);
	size_b = lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

void ft_less_possible_move(p_list **stack_a, p_list **stack_b)
{
	p_list	*tmp;
	int		min;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	min = INT_MAX;
	while (tmp)
	{
		if (ft_nbr_abs(tmp->cost_a) + ft_nbr_abs(tmp->cost_b) < ft_nbr_abs(min))
		{
			min = ft_nbr_abs(tmp->cost_a) + ft_nbr_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_move_cost(stack_a, stack_b, cost_a, cost_b);
}