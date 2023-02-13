/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:31:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/13 19:20:40 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Sorting three elements

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_node
{
	int				x;
	int				value;
	struct s_node	*next;
}					t_node;

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = value;
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
			printf("[*][%ld]", (long int)curr->x);
			break ;
		}
		printf("[*][%ld]->", (long int)curr->x);
		curr = curr->next;
	}
}

int		list_sorted(t_node **root)
{
	t_node	*curr;

	curr = *root;
	while (curr->next)
	{
		if (curr->x > curr->next->x)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sa(t_node **t_list_a)
{
	t_node	*second;

	if (!*t_list_a)
		return ;
	second = (*t_list_a)->next;
	(*t_list_a)->next = second->next;
	second->next = *t_list_a;
	*t_list_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_node **t_list_b)
{
	t_node	*second;

	if (!*t_list_b)
		return ;
	second = (*t_list_b)->next;
	(*t_list_b)->next = second->next;
	second->next = *t_list_b;
	*t_list_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_node **t_list_a, t_node **t_list_b)
{
	sa(t_list_a);
	sb(t_list_b);
	write(1, "ss\n", 3);
}

void	pa(t_node **t_list_a, t_node **t_list_b)
{
	t_node	*curr;

	if (!*t_list_b)
		return ;
	curr = *t_list_b;
	*t_list_b = curr->next;
	curr->next = *t_list_a;
	*t_list_a = curr;
	write(1, "pa\n", 3);
}

void	pb(t_node **t_list_b, t_node **t_list_a)
{
	t_node	*curr;

	if (!*t_list_a)
		return ;
	curr = *t_list_a;
	*t_list_a = curr->next;
	curr->next = *t_list_b;
	*t_list_b = curr;
	write(1, "pb\n", 3);
}

void	ra(t_node **t_list_a)
{
	t_node	*curr;
	t_node	*temp;

	if (!*t_list_a)
		return ;
	curr = *t_list_a;
	temp = *t_list_a;
	*t_list_a = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_node **t_list_b)
{
	t_node	*curr;
	t_node	*temp;

	if (!*t_list_b)
		return ;
	curr = *t_list_b;
	temp = *t_list_b;
	*t_list_b = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_node **t_list_a)
{
	t_node	*curr;
	t_node	*before_last;

	curr = *t_list_a;
	before_last = *t_list_a;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *t_list_a;
	*t_list_a = curr;
	before_last->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_node **t_list_b)
{
	t_node	*curr;
	t_node	*before_last;

	curr = *t_list_b;
	before_last = *t_list_b;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *t_list_b;
	*t_list_b = curr;
	before_last->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **t_list_a, t_node **t_list_b)
{
	rra(t_list_a);
	rrb(t_list_b);
	write(1, "rrr\n", 4);
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

// Logic to 3 elements:content
// I will start the sorting making two questions

// The top element is bigger than the bottom element?

// The top element is bigger than the middle element?

// 3, 1, 2 --> yes and yes --> (ra) --> 1, 2, 3(sorted);
// 3, 2, 1 --> yes and yes --> (sa) --> 2, 3, 1 --> (rra) --> 1, 2, 3(sorted)
// 2, 1, 3 --> yes and NO  --> (sa)  --> 1, 2, 3 (Sorted)
// 2, 3, 1 --> no and yes  --> (rra) --> 1, 2, 3(sorted);
// 1, 3, 2 --> no and no   --> (sa) --> 3, 1, 2 --> (ra) --> 1, 2, 3(Sorted)

// typedef struct s_node
// {
// 	int				x;
// 	int				value;
// 	struct s_node	*next;
// }					t_node;

void	sort_3_elements(t_node **a)
{
	t_node	*b;

	b = *a;
	while (b->next)
		b = b->next;
	if ((*a)->x > (*a)->next->x && (*a)->x > b->x && (*a)->next->x < b->x)
		ra(a);
	else if ((*a)->x > (*a)->next->x && (*a)->x > b->x && (*a)->next->x > b->x)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->x > (*a)->next->x && (*a)->x < b->x)
		sa(a);
	else if ((*a)->x < (*a)->next->x && (*a)->x > b->x)
		rra(a);
	else if ((*a)->x < (*a)->next->x && (*a)->x < b->x)
	{
		sa(a);
		ra(a);
	}
	return ;
}


int	sm(t_node **a)
{
	t_node	*temp;
	int		temp_menor;
	int		index_smallest;

	temp = (*a);
	index_smallest = 0;
	temp_menor = (*a)->x;
	while (temp)
	{
		if (temp_menor > temp->x)
			temp_menor = temp->x;

		temp = temp->next;
	}
	temp = (*a);
	while (temp != NULL)
	{
		if (temp->x == temp_menor)
			break ;
		temp = temp->next;
		index_smallest++;
	}
	return (index_smallest);
}

int	big(t_node **a)
{
	t_node	*temp;
	int		temp_maior;
	int		index_biggest;

	temp = (*a);
	index_biggest = 0;
	temp_maior = (*a)->x;
	while (temp)
	{
		if (temp_maior < temp->x)
			temp_maior = temp->x;
		temp = temp->next;
	}
	temp = (*a);
	while ( temp != NULL)
	{
		if (temp->x == temp_maior)
			break ;
		temp = temp->next;
		index_biggest++;
	}
	return (index_biggest);
}


// 23 possibilidades
// em 11 possibilidades teremos o menor ou o maior no topo (is_smallest == 0 )
// em 12 possibilidades teremos numeros intermediarios no topo

void	sort_4_elements(t_node **a, t_node **b)
{

	if (sm(a) == 0 || big(a) == 0)
	{
		printf("0");
		printf("\n");
		pb(b, a);
	}
	else if (sm(a) == 1 || big(a) == 1)
	{
		printf("1");
		sa(a);
		pb(a, b);
	}
	else if (sm(a) == 3 || big(a) == 3)
	{
		printf("2");
		ra(a);
		pb(a, b);
	}
	printList(a);
	printf("\n");
	sort_3_elements(a);
	pa(b, a);
	if (!(list_sorted(a)))
		ra(a);
}

int	main(void)
{
	t_node	*t_list_a;
	t_node	*t_list_b;

	t_list_a = NULL;
	t_list_b = NULL;
	insert_end(&t_list_a, 7);
	insert_end(&t_list_a, 2);
	insert_end(&t_list_a, 1);
	insert_end(&t_list_a, 4);

	//------------------------------------------


	printf("List A: ");
	printList(t_list_a);

	//sort_3_elements(&t_list_a);

	printf("\n");
	printf("\n");
	printf("\n");
	sort_4_elements(&t_list_a, &t_list_b);

	printList(t_list_a);


	deallocate(&t_list_a, 0);
	return (0);
}
