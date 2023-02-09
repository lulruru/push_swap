/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:01:19 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/07 17:16:14 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	addback(p_list **lst, p_list *new)
{
	p_list *tmp;

	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

void	ft_lstaddfront(p_list **lst, p_list *new)
{
	if(lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

p_list	*ft_lstlast(p_list *liste)
{
	if (!liste)
		return (NULL);
	while (liste->next)
		liste = liste->next;
	return (liste);
}

p_list	*ft_lstnew(int content)
{
	p_list *new;
	
	new = malloc(sizeof(p_list));
	if(!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

int	lstsize(p_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

