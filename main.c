/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:34 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/05 20:13:05 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* p_list *createliste(int ac, char **av)
{
	p_list *new;
	p_list *Data;
	int	i = 1;
	new = malloc(sizeof(p_list));
	while (i < ac)
	{
		Data->data = atoi(av[i]);
		Data->next = NULL;
		addback(&new, Data);
		i++;
	}
	new->next = NULL;
	return (new);
} */

p_list *ft_fusion(int ac, char **av)
{
	p_list *liste;
	p_list *g;
	p_list *d;
	int l;
	int	i;
	
	i = 1;
	g = 0;
	l = ac;
	while (i <= l / 2)
	{
		liste = ft_lstnew(atoi(av[i]));
		addback(&g, liste);
		i++;
	}
	g->next = NULL;
	return(g);
	
	
}

int main(int ac, char **av)
{
	p_list *new;
	p_list *pile_a;
	p_list *after;
	int i = 1;
	pile_a = 0;
/* 	while(i < ac)
	{
		new = ft_lstnew(atoi(av[i]));
		addback(&pile_a, new);
		i++;
	} */
	after = ft_fusion(ac,av);
	while (after)
	{
		printf("%d ", after->data);
		after = after->next;
	}
	
}