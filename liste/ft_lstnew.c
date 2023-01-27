/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:42:35 by russelenc         #+#    #+#             */
/*   Updated: 2023/01/27 10:47:55 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.h"

p_list *ft_lstnew(int content)
{
	p_list *new;
	
	new = malloc(sizeof(p_list));
	if(!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}