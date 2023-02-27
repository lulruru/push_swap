/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:51:40 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/27 15:56:32 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **src, t_list **target)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *target;
	*target = *src;
	*src = tmp;
}

void	push(t_list **src, t_list **target, char n)
{
	ft_push(src, target);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

/* int main(int argc, char **argv)
{
    t_list *pile_a = NULL;
    t_list *pile_b = NULL;
    t_list *temp = NULL;
    int i;

    if (argc != 7)
    {
        printf("Met 6 arguments");
        return 1;
    }
    for (i = 1; i <= 3; i++)
    {
        temp = (t_list *)malloc(sizeof(t_list));
        temp->data = atoi(argv[i]);
        temp->next = pile_a;
        pile_a = temp;
    }

    for (i = 3; i < 6; i++)
    {
        temp = (t_list *)malloc(sizeof(t_list));
        temp->data = atoi(argv[i]);
        temp->next = pile_b;
        pile_b = temp;
    }

    printf("Pile a avant : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    printf("Pile b avant : ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    push(&pile_a, &pile_b, 'b');

    printf("Pile a après : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    printf("Pile b après : ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    return 0;
}  */