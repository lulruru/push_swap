/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:45:47 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/08 08:36:58 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push3(p_list **stack_a,p_list **stack_b, int size)
{
	p_list *tmp;
	
	
}

void ft_trifusion(p_list **stack_a, p_list **stack_b, int size)
{
	int	mid;

	mid = size / 2;

	while (size > mid )
	{
		push(*stack_a, *stack_b, 'b');
		size--;
	}
	
}