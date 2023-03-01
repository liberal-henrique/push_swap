/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:24:21 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/01 19:47:53 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

int	gv_i_b_a(t_list **a, t_list **b, int position)
{
	t_list	*temp;
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

int	gv_i(t_list **a, int element)
{
	t_list	*temp;
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

t_list* cloneList(t_list **head)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	new_list = NULL;
	current = *head;
	while (current != NULL)
	{
		new_node = malloc(sizeof(t_list));
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

void	sortList(t_list **a)
{
	t_list	*current;
	t_list	*index;
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

int	small_i(t_list **a)
{
	t_list	*temp;
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

int	big_i(t_list **a)
{
	t_list	*temp;
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

int	ft_pultimo(t_list **a)
{
	t_list	*list_temp;
	int		pultimo;

	list_temp = cloneList(a);
	sortList(&list_temp);
	pultimo = list_temp->next->next->next->x;
	deallocate(&list_temp, 0);
	return (pultimo);
}

int	ft_meio(t_list **a)
{
	t_list	*list_temp;
	int		meio;

	list_temp = cloneList(a);
	sortList(&list_temp);
	meio = list_temp->next->next->x;
	deallocate(&list_temp, 0);
	return (meio);
}

int	cnt_rec(t_list *node)
{
	if (node == NULL)
		return (0);
	return (1 + cnt_rec(node->next));
}

void	send_desire(t_list **a, t_list **b, int meio, int pnultimo)
{
	if ((*a)->x == meio || (*a)->x == pnultimo)
		ra(a);
	else
		pb(b, a);
}

void	sort_3(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	if ((*a)->x > (*a)->next->x && (*a)->x > temp->x && (*a)->next->x < temp->x)
		ra(a);
	else if ((*a)->x > (*a)->next->x && (*a)->x > temp->x && (*a)->next->x > temp->x)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->x > (*a)->next->x && (*a)->x < temp->x)
		sa(a);
	else if ((*a)->x < (*a)->next->x && (*a)->x > temp->x)
		rra(a);
	else if ((*a)->x < (*a)->next->x && (*a)->x < temp->x)
	{
		sa(a);
		ra(a);
	}
	return ;
}

void	sort_4_elements(t_list **a, t_list **b)
{
	if (small_i(a) == 0 || big_i(a) == 0)
		pb(b, a);
	else if (small_i(a) == 1 || big_i(a) == 1)
	{
		sa(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	else if (small_i(a) == 3 || big_i(a) == 3)
	{
		rra(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	sort_3(a);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
}

void	sort_5_elements(t_list **a, t_list **b)
{
	int	meio;
	int	pnultimo;

	meio = ft_meio(a);
	pnultimo = ft_pultimo(a);
	while (cnt_rec(*a) != 3)
 		send_desire(a, b, meio, pnultimo);
	if (!list_sorted(a))
		sort_3(a);
	if ((*b)->x < (*b)->next->x)
		sb(b);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
	pa(a, b);
	if (!(list_sorted(a)))
		sa(a);
}

int	gv_i_mid(t_list **a)
{
	int		mid;
	int		size;

	mid = 0;
	size = cnt_rec(*a);
	if (size % 2 != 0)
		mid = (size / 2) + 1;
	else
		mid = (size / 2);
	return (mid);
}

int	give_value_mid(t_list **a)
{
	int		mid_value;
	int		index_mid;
	t_list	*temp;

	mid_value = 0;
	temp = cloneList(a);
	index_mid = gv_i_mid(a);
	sortList(&temp);
	while (index_mid >= 0 && temp != NULL)
	{
		if (index_mid == 0)
			mid_value = temp->x;
		index_mid--;
		temp = temp->next;
	}
	deallocate(&temp, 0);
	return (mid_value);
}

void	send_pb(t_list **a, t_list **b, int top, int bottom, int md_pnt)
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
	if ((*b)->x < md_pnt)
		rb(b);
}

int	numero_movi(t_list **a, int end)
{
	t_list *temp;
	int	i;

	temp = cloneList(a);
	sortList(&temp);
	i = 1;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	deallocate(&temp, 0);
	return (i);
}

int	start(t_list **a)
{
	t_list *temp;
	int	start;

	temp = cloneList(a);
	sortList(&temp);
	start = temp->x;
	deallocate(&temp, 0);
	return (start);
}

int	end(t_list **a)
{
	t_list *temp;
	int	end;

	temp = cloneList(a);
	sortList(&temp);
	end = 0;
	while (temp->next != NULL && end != 29)
	{
		end++;
		temp = temp->next;
	}
	end = temp->x;
	deallocate(&temp, 0);
	return (end);
}

int	midpoint(t_list **a, int i)
{
	t_list	*temp;
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

void	best_move(t_list **a, t_list **b, int start, int end)
{
	t_list	*temp;
	int	i;
	int	top;
	int	bottom;
	int flag;
	int	md_pnt;

	i = numero_movi(a, end);
	md_pnt = midpoint(a, i);
	while (*a && i-- != 0)
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
		send_pb(a, b, gv_i(a, top), (cnt_rec(*a) - gv_i(a, bottom)), md_pnt);
	}
}

int	sort_biggest_chunks_in_b(t_list **root)
{
	t_list	*last_value;
	t_list	*temp;
	int	biggest;

	last_value = (*root);
	temp = (*root);
	biggest = 0;
	while (last_value->next != NULL)
		last_value = last_value->next;
	while (temp->next != NULL)
	{
		if (temp->x < last_value->x)
			break;
		if (temp->x < temp->next->x)
			biggest = temp->next->x;
		temp = temp->next;
	}
	return (biggest);
}

int	i_last(t_list **root, int finish)
{
	t_list	*temp;
	int	index;

	temp = *root;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->x == finish)
			break;
		index++;
		temp = temp->next;
	}
	return (index);
}

int	i_first(t_list **root, int start)
{
	t_list	*temp;
	int	index;

	temp = *root;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->x == start)
			break;
		index++;
		temp = temp->next;
	}
	return (index);
}

int	md_chunk(t_list **root, int start, int finish)
{
	t_list	*temp;
	int		mid;
	int		result;

	temp = cloneList(root);
	sortList(&temp);
	mid = (i_last(&temp, finish) - i_first(&temp, start)) / 2;
	while (temp->next != NULL)
	{
		if (temp->x == start)
			break;
		temp = temp->next;
	}
	while (mid-- != 0)
		temp = temp->next;
	result = temp->x;
	deallocate(&temp, 0);
	return (result);
}

int	top_small(t_list *b)
{
	t_list *temp;
	t_list *last;
	int	small;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	small = temp->x ;
	while (temp->x > last->x)
	{
		if (small > temp->x)
			small = temp->x;
		temp = temp->next;
	}
	return (small);
}

int	bot_small(t_list *b)
{
	t_list *temp;
	int	small;

	temp = b;
	small = temp->x;
	while (temp->next != NULL)
	{
		if (small > temp->x)
			small = temp->x;
		temp = temp->next;
	}
	return (small);
}

int	top_big(t_list *b)
{
	t_list *temp;
	t_list *last;
	int	big;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	big = temp->x;
	while (temp->x > last->x)
	{
		if (big < temp->x)
			big = temp->x;
		temp = temp->next;
	}
	return (big);
}

int	bot_big(t_list *b)
{
	t_list *temp;
	int	big;

	temp = b;
	big = temp->x;
	while (temp->next != NULL)
	{
		if (big < temp->x)
			big = temp->x;
		temp = temp->next;
	}
	return (big);
}

void	back_ra(t_list **a, int n_control)
{

	if (cnt_rec(*a) <= 2 && list_sorted(a))
		return ;
	while (n_control-- != 0)
		rra(a);
}

void	back_pb(t_list **a, t_list **b, int n_control)
{
	while (n_control-- != 0)
		pa(a, b);
}

int	find_biggest_chunks_in_a(t_list **root, int n_moviments)
{
	t_list	*temp;
	int		biggest;

	temp = (*root);
	biggest = temp->x;
	while ( --n_moviments > 0)
	{
		if (biggest < temp->next->x)
			biggest = temp->next->x;
		temp = temp->next;
	}
	return (biggest);
}

int	find_smallest_chunks_in_a(t_list **root)
{
	t_list	*temp;
	int		smallest;

	temp = *root;
	smallest = 0;
	while (temp->next != NULL)
	{
		if (temp->x > temp->next->x)
			smallest = temp->next->x;
		temp = temp->next;
	}
	return (smallest);
}


void	sort_a(t_list **a, t_list **b, int n_moviments)
{
	t_list	*last;
	int	tmp;
	int	biggest;
	int	smallest;
	int	mid_pnt;
	int	ra_control;
	int	pb_control;

	tmp = n_moviments;
	ra_control = 0;
	pb_control = 0;
	last = (*a);
	while (--tmp != 0)
		last = last->next;
	if (list_sorted(a))
		return ;
	biggest = find_biggest_chunks_in_a(a, n_moviments);
	smallest = find_smallest_chunks_in_a(a);
	mid_pnt = md_chunk(a, smallest, biggest);
	while (n_moviments-- >= 1)
	{
		if ((*a)->x > mid_pnt && ++ra_control)
			ra(a);
		else if ((*a)->x <= mid_pnt && ++pb_control)
			pb(b, a);
	}
	back_ra(a, ra_control);
	if (!(list_sorted(a)))
		sort_a(a, b, ra_control);
	back_pb(a, b, pb_control);
	if (!(list_sorted(a)))
		sort_a(a, b, pb_control);
}

void	send_bot_b(t_list **a, t_list **b)
{
	t_list *temp;
	t_list *last;
	int	n;
	int	i;
	int	md_pnt;

	temp = *b;
	last = *b;
	n = 0;
	i = 0;
	md_pnt = 0;
	while (last->next != NULL)
	{
		last = last->next;
		md_pnt++;
		if (last->x > (*b)->x)
			n++;
		else
			n = 0;
	}
	last = *b;
	while (last->next != NULL && md_pnt-- >= n)
		last = last->next;
	md_pnt = md_chunk(b, bot_small(last), bot_big(last));
	n = 0;
	while (temp->x != last->x)
	{
		temp = *b;
		while (temp->next != NULL)
			temp = temp->next;
		rrb(b);
		if ((*b)->x >= md_pnt && ++i)
			pa(a, b);
		else
			n++;
	}
	sort_a(a, b, i);
	i = n;
	while (n-- != 0)
		pa(a, b);
	sort_a(a, b, i);
}

void	send_top_b(t_list **a, t_list **b)
{
	t_list *last;
	static int	i;
	static int	n;
	int	md_pnt;

	last = *b;
	while (last->next != NULL)
		last = last->next;
	md_pnt = md_chunk(b, top_small(*b), top_big(*b));
	while ((*b)->x > last->x && (*b))
	{
		if ((*b)->x >= md_pnt && ++i)
			pa(a, b);
		else if ((*b)->x < md_pnt && ++n)
			rb(b);
	}
	sort_a(a, b, i);
	i = n;
	while (n-- != 0)
	{
		rrb(b);
		pa(a, b);
	}
	sort_a(a, b, i);
}

void	send_rest(t_list **a, t_list **b)
{
	t_list *last;
	int	md_pnt;
	int	small;
	int	big;
	int	i;
	int	n;

	last = *b;
	small = last->x;
	big = last->x;
	n = 0;
	i = 0;
	while (last->next != NULL)
	{
		if (small > last->next->x)
			small = last->next->x;
		if (big < last->next->x)
			big = last->next->x;
		last = last->next;
	}
	md_pnt = md_chunk(b, small, big);
	while ((*b)->x != last->x)
	{
		if ((*b)->x > md_pnt && ++n)
			pa(a, b);
		else if ((*b)->x <= md_pnt && ++i)
			rb(b);
	}
	if ((*b)->x > md_pnt && ++n)
		pa(a, b);
	sort_a(a, b, n);
	n = i;
	while (i-- != 0)
		pa(a, b);
	sort_a(a, b, n);
}

void	sort_biggest(t_list **a, t_list **b)
{
	t_list	*temp;

	while (cnt_rec(*a) != 0)
		best_move(a, b, start(a), end(a));
	while (cnt_rec(*b) > 15)
	{
		temp = (*b);
		while (temp->next != NULL)
			temp = temp->next;
		if ((*b)->x > temp->x)
			send_top_b(a, b);
		else if ((*b)->x < temp->x)
			send_bot_b(a, b);
	}
	send_rest(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	list initialize();
	if (cnt_cursive(*a) <= 3)
		sort_3();
	else if (cnt_cursive(*a) <= 5)
		sort_5_elements();
	else
		sort_biggest();
	deallocate(&a, 0);
	return (0);
}
