/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:30:27 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/06 17:49:09 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

void	freelastack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}


void	freetout(t_list **stack_a, t_list **stack_b, char *str)
{
	freelastack(stack_a);
	freelastack(stack_b);
	free(str);
}


void	jaideserreurs(t_list **stack_a, t_list **stack_b, char *str)
{
	freetout(stack_a, stack_b, str);
	get_next_line(0, 1);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
