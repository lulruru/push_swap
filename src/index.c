/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:12:11 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/07 19:57:36 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
ft_indexer est une fonction qui permet d'attribuer un index 
a chaque elemt du plus petit au plus grand

	STACK	54	5	8	0	-2
    INDEX  [5] [3] [4] [2] [1]

*/
void	ft_indexer(t_list *stack_a, int size)
{
	t_list	*lst;
	t_list	*high;
	int		data;

	while (--size > 0)
	{
		lst = stack_a;
		data = INT_MIN;
		high = NULL;
		while (lst)
		{
			if (lst->data == INT_MIN && lst->index == 0)
				lst->index = 1;
			if (lst->data > data && lst->index == 0)
			{
				data = lst->data;
				high = lst;
				lst = stack_a;
			}
			else
				lst = lst-> next;
		}
		if (high != NULL)
			high->index = size;
	}
}

/*
*ft_init_pos est un fonction qui permet d'attribuer une position 
a chaque element de la stack 

	STACK	54	5	8	0	-2
    POS    [0] [1] [2] [3] [3]
ca va nous permettre de calculer le cout pour changer un element
de position.
*/
static void	ft_init_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
/*
ft_lowest_index_pos fonction qui permet de recuperer la position
de l'index le plus faible
*/

int	ft_lowest_index_pos(t_list **stack)
{
	int		low_p;
	int		low_i;
	t_list	*tmp;

	low_i = INT_MAX;
	tmp = *stack;
	ft_init_pos(stack);
	low_p = tmp->pos;
	while (tmp)
	{
		if (tmp->index < low_i)
		{
			low_i = tmp->index;
			low_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (low_p);
}

/*
ft_target fonction qui permet de regarder ou est ce que dans la pile a
l'element de pile b aura la meilleur position. Pour cela
on va comparer les index.
*/

int	ft_target(t_list **stack, int index_b, \
				int target_i, int target_p)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_i)
		{
			target_i = tmp->index;
			target_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_i != INT_MAX)
		return (target_p);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < target_i)
		{
			target_i = tmp->index;
			target_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_p);
}
/*
Fonction qui permet d'attribuer une valeur a la variable target
de la structure. de cette maniere chaque element du tableau
possede la sa position dans la liste des elements.
*/

void	ft_target_best_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		target_p;

	tmp = *stack_b;
	ft_init_pos(stack_a);
	ft_init_pos(stack_b);
	target_p = 0;
	while (tmp)
	{
		target_p = ft_target(stack_a, tmp->index, INT_MAX, target_p);
		tmp->target = target_p;
		tmp = tmp->next;
	}
}
