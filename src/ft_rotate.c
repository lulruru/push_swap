/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:33:56 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/27 15:56:26 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Décale d’une position vers le haut tous les élements de la pile.
Le premier élément devient le dernier.*/

void	ft_rotate(t_list **src)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *src;
	*src = (*src)->next;
	last = ft_lstlast(*src);
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate(t_list **stack, char n)
{
	ft_rotate(stack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate2(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
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

    for (i = 4; i <= 6; i++)
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
    printf("\n\n");

    ft_rotate(&pile_a);

    printf("Pile a après : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    printf("Pile b après : ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    return 0;
} */