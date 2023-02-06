/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:19:26 by rencarna          #+#    #+#             */
/*   Updated: 2023/02/06 17:10:51 by rencarna         ###   ########.fr       */
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

size_t ft_strlen(char *str)
{
	size_t i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/* int main (int ac, char **av)
{
	int	i;
	i = ft_atol(av[1]);
	printf("%d", i);
} */