/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:38:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/21 18:05:27 by russelenc        ###   ########.fr       */
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
	int				index;
	int				data;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	p_list;


/*          LISTE OPERATION           */
p_list	*ft_lstlast(p_list *liste);
p_list	*ft_lstnew(int content);
void	addback(p_list **lst, p_list *new);
int		lstsize(p_list *lst);
void	indexer(p_list *stack_a, int size);
void	ft_lstaddfront(p_list **lst, p_list *new);

/*          UTILS          */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
long	ft_atol(char *str);
p_list	*do_list(int ac, char **av);
void	ft_error(p_list **stack_a, p_list **stack_b);
void	ft_free(p_list **stack);
int		ft_sorted(p_list *stack);
int		ft_pars(int ac, char **av);
int		ft_nbr_abs(int nb);

/*          STACK UTILS         */
void	swapboth(p_list **stack_a, p_list **stack_b);
void	swap(p_list **stack, char c);
void	ft_swap(p_list *stack);
void	ft_rotate(p_list **src);
void	rotate(p_list **stack, char n);
void	rotate2(p_list **stack_a, p_list **stack_b);
void	ft_push(p_list **src, p_list **target);
void	push(p_list **src, p_list **target, char n);
void	reverse_rotate(p_list **stack, char n);
void	ft_reverse_rotate(p_list **src);
void	printdta(p_list *stacka);
void	reverse_rotate_both(p_list **stack_a,p_list **stack_b);

/*          ALGO         */
void	algo3(p_list **stack_a);
void	ft_sort(p_list **stack_a, p_list **stack_b);
void	push3(p_list **stack_a,p_list **stack_b);
void ft_less_possible_move(p_list **stack_a, p_list **stack_b);;

/*          COST         */
void	ft_move_cost(p_list **stack_a, p_list **stack_b, int cost_a, int cost_b);
void	ft_cost(p_list **stack_a, p_list **stack_b);

/*          INDEX/POS         */
int		ft_lowest_index_pos(p_list **stack);
void	ft_target_best_pos(p_list **stack_a, p_list **stack_b);
void	ft_indexer(p_list *stack_a, int size);


#endif