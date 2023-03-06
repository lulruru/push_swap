/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:30:52 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/06 10:26:07 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <string.h>

void	read_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		ft_swap(*stack_a);
	else if (ft_strcmp(str, "sb\n"))
		ft_swap(*stack_b);
	else if (ft_strcmp(str, "pa\n"))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n"))
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(str, "ra\n"))
		ft_rotate(stack_a);
	else if (ft_strcmp(str, "rb\n"))
		ft_rotate(stack_b);
	else if (ft_strcmp(str, "rra\n"))
		ft_reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		ft_reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		reverse_rotate_both_check(stack_a, stack_b);
	
}
void printdta(t_list *stacka)
{
	while (stacka)
	{
		printf("%d ", stacka->data);
		stacka = stacka->next;	
	}
	printf("\n");
}

void boucle_read(t_list *stack_a, t_list *stack_b)
{
	char *str;

	str = get_next_line(0);
	while (str != 0)
	{
		read_instruction(&stack_a, &stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (!stack_b && stack_a && ft_sorted(stack_a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	
}

int main(int ac, char **av)
{	
	t_list	*stack_a;
	t_list	*stack_b;

	if(ac < 2)
		return (0); 
/* 	if (ft_pars(ac, av))
		ft_error(NULL, NULL); */
	stack_b = NULL;
	stack_a = do_list(ac, av);
	if (ft_sorted(stack_a))
	{
		ft_free(&stack_a);
		return(0);
	}
	boucle_read(stack_a, stack_a);
	ft_free(&stack_a);
	ft_free(&stack_b);
} 