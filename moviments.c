/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:32:24 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/09 13:21:14 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}					t_node;

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->content = value;
	new_node->next = NULL;
	if (*root == NULL)
	{
		new_node->next = *root;
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	printList(t_node *root)
{
	t_node	*curr;

	curr = root;
	while (curr != NULL)
	{
		if (curr->next == NULL)
		{
			printf("[*][%ld]", (long int)curr->content);
			break ;
		}
		printf("[*][%ld]->", (long int)curr->content);
		curr = curr->next;
	}
}

void	deallocate(t_node **root, int message)
{
	t_node	*temp;

	while (*root)
	{
		temp = (*root)->next;
		free(*root);
		*root = temp;
	}
	root = NULL;
	if (message == 1)
		exit(write(1, "errorDeallo\n", 12));
}

void	sa(t_node **t_list_a)
{
	t_node	*second;

	second = (*t_list_a)->next;
	(*t_list_a)->next = second->next;
	second->next = *t_list_a;
	*t_list_a = second;
}

void	sb(t_node **t_list_b)
{
	t_node	*second;

	second = (*t_list_b)->next;
	(*t_list_b)->next = second->next;
	second->next = *t_list_b;
	*t_list_b = second;
}

void	ss(t_node **t_list_a, t_node **t_list_b)
{
	t_node	*second_a;
	t_node	*second_b;

	second_a = (*t_list_a)->next;
	(*t_list_a)->next = second_a->next;
	second_a->next = *t_list_a;
	*t_list_a = second_a;
	second_b = (*t_list_b)->next;
	(*t_list_b)->next = second_b->next;
	second_b->next = (*t_list_b);
	*t_list_b = second_b;
}

void	pa(t_node **t_list_a, t_node **t_list_b)
{
	
}

int	main(void)
{
	int		i;
	int		number;
	t_node	*t_list_a;
	t_node	*t_list_b;

	i = 0;
	t_list_a = NULL;
	t_list_b = NULL;
	insert_end(&t_list_a, 5);
	insert_end(&t_list_a, 4);
	insert_end(&t_list_a, 8);
	insert_end(&t_list_a, 9);
	insert_end(&t_list_a, 10);
	printf("\n");
	insert_end(&t_list_b, 12);
	insert_end(&t_list_b, 14);
	insert_end(&t_list_b, 16);
	insert_end(&t_list_b, 17);
	insert_end(&t_list_b, 19);
	printList(t_list_a);
	printf("\n");
	printList(t_list_b);
	ss(&t_list_a, &t_list_b);
	printList(t_list_a);
		printf("\n");
	printList(t_list_b);

	printf("\n");
	printList(t_list_a);
		printf("\n");
	deallocate(&t_list_a, 0);
	return (0);
}
