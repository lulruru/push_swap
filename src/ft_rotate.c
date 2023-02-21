/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:33:56 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/18 13:31:49 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Décale d’une position vers le haut tous les élements de la pile.
Le premier élément devient le dernier.*/

void	ft_rotate(p_list **src)
{
	p_list	*tmp;
	p_list	*last;

	tmp = *src;
	*src = (*src)->next;
	last = ft_lstlast(*src);
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate(p_list **stack, char n)
{
	ft_rotate(stack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate2(p_list **stack_a, p_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

/* int main(int argc, char **argv)
{
    p_list *pile_a = NULL;
    p_list *pile_b = NULL;
    p_list *temp = NULL;
    int i;

    if (argc != 7)
    {
        printf("Met 6 arguments");
        return 1;
    }
    for (i = 1; i <= 3; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
        temp->data = atoi(argv[i]);
        temp->next = pile_a;
        pile_a = temp;
    }

    for (i = 4; i <= 6; i++)
    {
        temp = (p_list *)malloc(sizeof(p_list));
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