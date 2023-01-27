/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:56:32 by russelenc         #+#    #+#             */
/*   Updated: 2023/01/27 10:58:35 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

p_list *ft_lstlast(p_list *liste)
{
	if (!liste)
		return ;
	while (liste)
		liste = liste->next;
	return (liste);
}