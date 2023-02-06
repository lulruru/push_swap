/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:37:11 by russelenc         #+#    #+#             */
/*   Updated: 2023/02/03 15:41:37 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*Décale d’une position vers le bas tous les élements de
la pile . Le dernier élément devient le premier*/
void ft_reverse_rotate(p_list **src)
{
	p_list	*temp;
	p_list	*last;

	if (!src || !*src || !(*src)->next)
		return ;
	temp = *src;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *src;
	*src = last;
}

void reverse_rotate(p_list **stack, char n)
{
	ft_reverse_rotate(stack);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

int main(int argc, char **argv)
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

    reverse_rotate(&pile_a, 'a');

    printf("Pile a après : ");
    for (temp = pile_a; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    printf("Pile b après : ");
    for (temp = pile_b; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");

    return 0;
}