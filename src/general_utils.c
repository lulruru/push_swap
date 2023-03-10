/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:19:26 by rencarna          #+#    #+#             */
/*   Updated: 2023/03/06 17:21:04 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

long	ft_atol(char *str)
{
	int			i;
	int			sign;
	int long	r;

	i = 0;
	sign = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * sign);
}

void	ft_free(t_list **stack)
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

void	ft_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_free(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_free(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
/* int main (int a, char **av)
{
	int	i;ss
	i = ft_atol(av[1]);
	printf("%d", i);
} */