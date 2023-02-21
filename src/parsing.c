/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:44:14 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/18 13:44:15 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_pars(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!is_num(av[i][j]))
			return (1);
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

p_list	*do_list(int ac, char **av)
{
	p_list		*new;
	p_list		*stack_a;
	int			i;
	long int	nb;

	i = 1;
	stack_a = 0;
	while (i < ac)
	{
		nb = ft_atol(av[i]);
		if(nb > INT_MAX || nb < INT_MIN)
			ft_error(&stack_a, NULL);
		new = ft_lstnew(nb);
		addback(&stack_a, new);
		i++;
	}
	return (stack_a);
}

int ft_sorted(p_list *stack)
{
	while(stack->next)
	{
		if (stack->data > stack->next->data)
			return(0);
		stack = stack->next;
	}
	return (1);
}

int ft_nbr_abs(int nb)
{
	if (nb < 0)
		return (nb *= -1);
	return (nb);
}
/* int main(int ac, char **av)
{
	int	i;
	
	if (ac >= 2)
	{
		printf("sortie : %d \n", ft_pars(ac,av));
		if (ft_pars(ac,av) == 1)
			printf("ERROR");
		else if (ft_pars(ac, av) == 0)
			printf("its god");
	}
	printf("\n");
} */