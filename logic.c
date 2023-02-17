/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:31:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/17 16:25:28 by lliberal         ###   ########.fr       */
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

typedef struct s_chunk
{
	int				n_chunks;
	int				n_elements;
	struct s_struck	*next;
}					t_chunk;


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
	//write(1, "pb\n", 3);
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
	//write(1, "ra\n", 3);
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
	//write(1, "rb\n", 3);
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
	//write(1, "rra\n", 4);
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

int	give_index_b_a(t_node **a, t_node **b, int position)
{
	t_node	*temp;
	int		index_b_in_a;
	int		pos;

	temp = (*a);
	pos = 0;
	index_b_in_a = 0;
	if (position == 0)
		pos = (*b)->x;
	if (position == 1)
		pos = (*b)->next->x;
	while (temp != NULL)
	{
		if (pos > temp->x)
			index_b_in_a++;
		if (pos < temp->x)
			break ;
		temp = temp->next;
	}
	return (index_b_in_a);
}

int	give_index(t_node **a, int element)
{
	t_node	*temp;
	int		index_a;

	temp = (*a);
	index_a = 0;
	while (temp != NULL)
	{
		if (element == temp->x)
			break ;
		index_a++;
		temp = temp->next;
	}
	return (index_a);
}

t_node* cloneList(t_node **head)
{
	t_node	*new_list;
	t_node	*new_node;
	t_node	*prev;
	t_node	*current;

	prev = NULL;
	new_list = NULL;
	current = *head;
	while (current != NULL)
	{
		new_node = malloc(sizeof(t_node));
		new_node->x = current->x;
		new_node->next = NULL;
		if (prev != NULL) {
			prev->next = new_node;
		} else {
			new_list = new_node;
		}
		prev = new_node;
		current = current->next;
	}
	return (new_list);
}

void	sortList(t_node **a)
{
	t_node	*current;
	t_node	*index;
	int temp;

	temp = 0;
	index = NULL;
	current = *a;
	if(*a == NULL)
		return ;
	else {
		while(current != NULL) {
			index = current->next;
			while(index != NULL) {
				if(current->x > index->x) {
					temp = current->x;
					current->x = index->x;
					index->x = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
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

int	ft_pultimo(t_node **a)
{
	t_node	*list_temp;
	int		pultimo;

	list_temp = cloneList(a);
	sortList(&list_temp);
	pultimo = list_temp->next->next->next->x;
	deallocate(&list_temp, 0);
	return (pultimo);
}

int	ft_meio(t_node **a)
{
	t_node	*list_temp;
	int		meio;

	list_temp = cloneList(a);
	sortList(&list_temp);
	meio = list_temp->next->next->x;
	deallocate(&list_temp, 0);
	return (meio);
}

int	cnt_recursive(t_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + cnt_recursive(node->next));
}

void	send_desire(t_node **a, t_node **b, int meio, int pnultimo)
{
	if ((*a)->x == meio || (*a)->x == pnultimo)
		ra(a);
	else
		pb(b, a);
}

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

void	sort_4_elements(t_node **a, t_node **b)
{
	if (sm(a) == 0 || big(a) == 0)
		pb(b, a);
	else if (sm(a) == 1 || big(a) == 1)
	{
		sa(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	else if (sm(a) == 3 || big(a) == 3)
	{
		rra(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	sort_3_elements(a);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
}

void	sort_5_elements(t_node **a, t_node **b)
{
	int	meio;
	int	pnultimo;

	meio = ft_meio(a);
	pnultimo = ft_pultimo(a);
	while (cnt_recursive(*a) != 3)
 		send_desire(a, b, meio, pnultimo);
	if (!list_sorted(a))
		sort_3_elements(a);
	if ((*b)->x < (*b)->next->x)
		sb(b);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
	pa(a, b);
	if (!(list_sorted(a)))
		sa(a);
}

int	give_index_mid(t_node **a)
{
	int		mid;
	int		size;

	mid = 0;
	size = cnt_recursive(*a);
	if (size % 2 != 0)
		mid = (size / 2) + 1;
	else
		mid = (size / 2);
	// printf("%i\n", size);
	// printf("%i\n", mid);
	return (mid);
}

int	give_value_mid(t_node **a)
{
	int		mid_value;
	int		index_mid;
	t_node	*temp;

	mid_value = 0;
	temp = cloneList(a);
	index_mid = give_index_mid(a);
	sortList(&temp);
	while (index_mid >= 0 && temp != NULL)
	{
		if (index_mid == 0)
			mid_value = temp->x;
		index_mid--;
		temp = temp->next;
	}
	return (mid_value);
}

//Preciso criar "algo" que va guardar o meu numero de elementos
//em cada chunck.
//Se nao enviarmos o midpoint sera o maior de cada chunk

// int	*chunks(t_node **a, int	numbers, int n_chunk)
// {
// 	int	*chunks;

// 	n_chunks = chunks(numbers, )
// 	chunks = malloc(sizeof(int) * n_chunks);

// }

// void	send_sml_mid(t_node **a, t_node **b)
// {
// 	int		size;
// 	int		mov;
// 	int		mid_pnt;
// 	//t_chunk	*temp_chunk;

// 	size = cnt_recursive(*a);
// 	while (size > 3)
// 	{
// 		mid_pnt = give_value_mid(a);
// 		mov = (cnt_recursive(*a)/2);
// 		//chunks = chunks(mov, 1);
// 		while (mov > 0)
// 		{
// 			if ((*a)->x < mid_pnt)
// 			{
// 				pb(b, a);
// 				mov--;
// 				size--;
// 			}
// 			else
// 				ra(a);
// 			if (size == 3)
// 				break ;
// 		}
// 	}
// 	//return (chunks);
// }

int	midpoint(t_node **a, int i)
{
	t_node	*temp;
	int	value;

	temp = cloneList(a);
	sortList(&temp);
	i = i/2;
	while (i-- != 0 && temp->next != NULL)
		temp = temp->next;
	value = temp->x;
	deallocate(&temp, 0);
	return (value);
}


void	send_pb(t_node **a, t_node **b, int top, int bottom, int mid_point)
{
	if (top <= bottom)
	{
		while (top-- != 0)
			ra(a);
		pb(b, a);
	}
	else if (bottom < top)
	{
		while (bottom-- != 0)
			rra(a);
		pb(b, a);
	}
	if ((*b)->x < mid_point)
		rb(b);
}

void	best_move(t_node **a, t_node **b, int start, int end)
{
	t_node	*temp;
	int	i;
	int	top;
	int	bottom;
	int flag;
	int	mid_point;

	i = 0.4 * cnt_recursive(*a);
	if (i > 40)
		i = 40;
	mid_point = midpoint(a, i);
	while (*a && i != 0)
	{
		flag = 0;
		temp = (*a);
		while (temp->next != NULL)
		{
			if ((temp->x >= start && temp->x <= end) && flag == 0)
			{
				top = temp->x;
				flag = 1;
			}
			if (temp->x >= start && temp->x <= end)
				bottom = temp->x;
			temp = temp->next;
		}
		send_pb(a, b, give_index(a, top), (cnt_recursive(*a) - give_index(a, bottom)), mid_point);
		i--;
	}
}

// void	sort_biggest(t_node **a, t_node **b)
// {
// 	int	*chunks;

// 	chunks = malloc(sizeof(int) * send_sml_mid(a, b));
// 	send_sml_mid(a, b);
// 	sort_3_elements(a);
// 	printf("HEYYY: %ls\n", chunks);
// }


int	main(void)
{
	//int	count;
	t_node	*t_list_a;
	t_node	*t_list_b;

	//count = 100;
	t_list_a = NULL;
	t_list_b = NULL;
	insert_end(&t_list_a, 36);
	insert_end(&t_list_a, 89);
	insert_end(&t_list_a, 29);
	insert_end(&t_list_a, 50);
	insert_end(&t_list_a, 93);

	insert_end(&t_list_a, 33);
	insert_end(&t_list_a, 5);
	insert_end(&t_list_a, 64);
	insert_end(&t_list_a, 13);
	insert_end(&t_list_a, 15);

	insert_end(&t_list_a, 47);
	insert_end(&t_list_a, 27);
	insert_end(&t_list_a, 83);
	insert_end(&t_list_a, 49);
	insert_end(&t_list_a, 0);

	insert_end(&t_list_a, 76);
	insert_end(&t_list_a, 77);
	insert_end(&t_list_a, 90);
	insert_end(&t_list_a, 1);
	insert_end(&t_list_a, 82);

	insert_end(&t_list_a, 56);
	insert_end(&t_list_a, 55);
	insert_end(&t_list_a, 92);
	insert_end(&t_list_a, 28);
	insert_end(&t_list_a, 25);

	insert_end(&t_list_a, 53);
	insert_end(&t_list_a, 54);
	insert_end(&t_list_a, 44);
	insert_end(&t_list_a, 57);
	insert_end(&t_list_a, 88);

	insert_end(&t_list_a, 35);
	insert_end(&t_list_a, 37);
	insert_end(&t_list_a, 85);
	insert_end(&t_list_a, 41);
	insert_end(&t_list_a, 42);

	insert_end(&t_list_a, 78);
	insert_end(&t_list_a, 79);
	insert_end(&t_list_a, 52);
	insert_end(&t_list_a, 39);
	insert_end(&t_list_a, 86);

	insert_end(&t_list_a, 46);
	insert_end(&t_list_a, 45);
	insert_end(&t_list_a, 74);
	insert_end(&t_list_a, 73);
	insert_end(&t_list_a, 81);


	insert_end(&t_list_a, 51);
	insert_end(&t_list_a, 98);
	insert_end(&t_list_a, 38);
	insert_end(&t_list_a, 65);
	insert_end(&t_list_a, 48);

	insert_end(&t_list_a, 22);
	insert_end(&t_list_a, 32);
	insert_end(&t_list_a, 60);
	insert_end(&t_list_a, 61);
	insert_end(&t_list_a, 75);

	insert_end(&t_list_a, 72);
	insert_end(&t_list_a, 30);
	insert_end(&t_list_a, 62);
	insert_end(&t_list_a, 31);
	insert_end(&t_list_a, 63);

	insert_end(&t_list_a, 23);
	insert_end(&t_list_a, 67);
	insert_end(&t_list_a, 26);
	insert_end(&t_list_a, 68);
	insert_end(&t_list_a, 10);

	insert_end(&t_list_a, 59);
	insert_end(&t_list_a, 94);
	insert_end(&t_list_a, 66);
	insert_end(&t_list_a, 40);
	insert_end(&t_list_a, 34);

	insert_end(&t_list_a, 99);
	insert_end(&t_list_a, 43);
	insert_end(&t_list_a, 84);
	insert_end(&t_list_a, 7);
	insert_end(&t_list_a, 100);

	insert_end(&t_list_a, 80);
	insert_end(&t_list_a, 14);
	insert_end(&t_list_a, 97);
	insert_end(&t_list_a, 69);
	insert_end(&t_list_a, 96);

	insert_end(&t_list_a, 70);
	insert_end(&t_list_a, 18);
	insert_end(&t_list_a, 20);
	insert_end(&t_list_a, 95);
	insert_end(&t_list_a, 58);

	insert_end(&t_list_a, 21);
	insert_end(&t_list_a, 4);
	insert_end(&t_list_a, 6);
	insert_end(&t_list_a, 16);
	insert_end(&t_list_a, 91);

	insert_end(&t_list_a, 2);
	insert_end(&t_list_a, 24);
	insert_end(&t_list_a, 19);
	insert_end(&t_list_a, 17);
	insert_end(&t_list_a, 12);

	insert_end(&t_list_a, 8);
	insert_end(&t_list_a, 71);
	insert_end(&t_list_a, 9);
	insert_end(&t_list_a, 3);
	insert_end(&t_list_a, 11);

	//Primeiro mid value 51
	//Segundo mid value 76
	// terceiro mid value 89
	// Quarto mid value 95
	// Quarto mid value 98
	// sorted 3


	//------------------------------------------

	printf("List A: ");
	printList(t_list_a);
	printf("\n");
	printf("\n");

	printf("Size a: %i\n", cnt_recursive(t_list_a));

	//sort_3_elements(&t_list_a);

	// printf("\n");
	// printf("\n");
	// //sort_5_elements(&t_list_a, &t_list_b);
	// //sort_biggest(&t_list_a, &t_list_b);

	// printf("\n");
	// printf("List A: ");
	// printList(t_list_a);

	// printf("\n");
	// printf("List B: ");
	// printList(t_list_b);

	printf("\n");
	printf("\n");
	printf("\n");

	best_move(&t_list_a, &t_list_b, 0, 39);

	printf("List A: ");
	printList(t_list_a);

	printf("\n");
	printf("Size a: %i\n", cnt_recursive(t_list_a));
	printf("\n");
	printf("\n");
	printf("List B: ");
	printList(t_list_b);
	printf("\n");
	printf("Size B: %i\n", cnt_recursive(t_list_b));
	printf("\n");
	printf("\n");
	printf("Result should be: ");
	printf("\n");
	sortList(&t_list_a);
	printList(t_list_a);
	printf("\n");
	printf("\n");

	sortList(&t_list_b);
	printList(t_list_b);

	deallocate(&t_list_a, 0);
	return (0);
}


