/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:19 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/03 17:54:18 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

int		small_i(t_list **a)
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

int		big_i(t_list **a)
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

int		ft_pultimo(t_list **a)
{
	t_list	*list_temp;
	int		pultimo;

	list_temp = cloneList(a);
	sortList(&list_temp);
	pultimo = list_temp->next->next->next->x;
	deallocate(&list_temp, 0);
	return (pultimo);
}

int		ft_meio(t_list **a)
{
	t_list	*list_temp;
	int		meio;

	list_temp = cloneList(a);
	sortList(&list_temp);
	meio = list_temp->next->next->x;
	deallocate(&list_temp, 0);
	return (meio);
}

int		cnt_rec(t_list *node)
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


//-----Send numbers in a organized way to Stack B-----//

int		gv_i_mid(t_list **a)
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

int		give_value_mid(t_list **a)
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

int		numero_movi(t_list **a, int end)
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

int		start(t_list **a)
{
	t_list *temp;
	int	start;

	temp = cloneList(a);
	sortList(&temp);
	start = temp->x;
	deallocate(&temp, 0);
	return (start);
}

int		end(t_list **a)
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

