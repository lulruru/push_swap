/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:38:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/03 15:43:45 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				index;
	int				data;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

/*          LISTE OPERATION           */
t_list	*ft_lstlast(t_list *liste);
t_list	*ft_lstnew(int content);
void	addback(t_list **lst, t_list *new);
int		lstsize(t_list *lst);
void	indexer(t_list *stack_a, int size);
void	ft_lstaddfront(t_list **lst, t_list *new);

/*          UTILS          */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
long	ft_atol(char *str);
t_list	*do_list(int ac, char **av);
void	ft_error(t_list **stack_a, t_list **stack_b);
void	ft_free(t_list **stack);
int		ft_sorted(t_list *stack);
int		ft_pars(int ac, char **av);
int		ft_nbr_abs(int nb);

/*          STACK UTILS         */
void	swapboth(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack, char c);
void	ft_swap(t_list *stack);
void	ft_rotate(t_list **src);
void	rotate(t_list **stack, char n);
void	rotate2(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **src, t_list **target);
void	push(t_list **src, t_list **target, char n);
void	reverse_rotate(t_list **stack, char n);
void	ft_reverse_rotate(t_list **src);
void	printdta(t_list *stacka);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_both_check(t_list **stack_a, t_list **stack_b);

/*          ALGO         */
void	algo3(t_list **stack_a);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	push3(t_list **stack_a, t_list **stack_b);
void	ft_less_possible_move(t_list **stack_a, t_list **stack_b);

/*          COST         */
void	ft_move_cost(t_list **stack_a, t_list **stack_b, \
						int cost_a, int cost_b);
void	ft_cost(t_list **stack_a, t_list **stack_b);

/*          INDEX/POS         */
int		ft_lowest_index_pos(t_list **stack);
void	ft_target_best_pos(t_list **stack_a, t_list **stack_b);
void	ft_indexer(t_list *stack_a, int size);

#endif