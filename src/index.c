/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:12:11 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/18 19:21:26 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
ft_indexer est une fonction qui permet d'attribuer un index 
a chaque elemt du plus petit au plus grand

	STACK	54	5	8	0	-2
    INDEX  [5] [3] [4] [2] [1]

*/
void ft_indexer(p_list *stack_a, int size)
{
	p_list *lst;
	p_list *high;
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
static void ft_init_pos(p_list **stack)
{
	p_list *tmp;
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
int	ft_lowest_index_pos(p_list **stack)
{
	int low_p;
	int	low_i;
	p_list *tmp;

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
*	--- Exemple:
*		target_p est initialise a INT_MAX
*		B index: 3
*		A indexes: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_p =  9
*		4 > 3 && 4 < 9 			: target_p = 4
*		2 < 3 && 2 < 4			: no update!
*	target_p prend la position du 4 eme index car il est l'index le plus proche.
*	--- Exemple:
*		B index: 20
*		A contains indexes: 16 4 3
*		16 < 20					: target_pos = INT_MAX
*		4  < 20					: target_pos = INT_MAX
*		3  < 20					: target_pos = INT_MAX
*		target_p n'ayant pas ete modifier, il est donc l'index le plus haut.
*		16 < 20					: target_pos = 20
*		4  < 20					: target_pos  = 4
*		3  < 20					: target_pos = 3
*		target_p sera donc a la troisieme position.
*/

int ft_target(p_list **stack,int index_b, int target_i, int target_p)
{
	p_list *tmp;
	
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_i )
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
void	ft_target_best_pos(p_list **stack_a, p_list **stack_b)
{
	p_list *tmp;
	int	target_p;

	tmp = *stack_b;
	ft_init_pos(stack_a);
	ft_init_pos(stack_b);
	target_p = 0;
	while (tmp)
	{
		target_p = ft_target(stack_a,tmp->index, INT_MAX, target_p);
		tmp->target = target_p;
		tmp = tmp->next;
	}
}
