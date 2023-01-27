/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:20:04 by russelenc         #+#    #+#             */
/*   Updated: 2023/01/27 11:51:20 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap(p_list **stack)
{
	int	tmp;
	
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void swap(p_list **stack, char c)
{
	ft_swap(stack);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_pucthar_fd('\n');
}

void swapboth(p_list **stack_a, p_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putchar_fd("ss\n", 1);
}