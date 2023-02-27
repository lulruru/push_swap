/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:20:04 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/27 15:56:23 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* Intervertit les 2 premiers éléments au sommet de la pile. 
Ne fait rien s’il n’y en a qu’un ou aucun. */
void	ft_swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL && stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	swap(t_list **stack, char c)
{
	ft_swap(*stack);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	swapboth(t_list **stack_a, t_list **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
