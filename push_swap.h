/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:38:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/03 14:37:04 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	p_list;


/*          LISTE OPERATION           */
p_list	*ft_lstlast(p_list *liste);
p_list	*ft_lstnew(int content);
void	addback(p_list **lst, p_list *new);
int		lstsize(p_list *lst);

/*          UTILS          */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
long	ft_atol(char *str);

/*          STACK UTILS         */
void swapboth(p_list **stack_a, p_list **stack_b);
void swap(p_list **stack, char c);
void ft_swap(p_list **stack);
void ft_rotate(p_list **src);
void rotate(p_list **stack, char n);
void rotate2(p_list **stack_a, p_list **stack_b);
void ft_push(p_list **src, p_list **target);
void push(p_list **src, p_list **target, char n);

int	ft_pars(int ac, char **av);


#endif