/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:32:24 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/02 11:34:39 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sa(t_list **a)
{
	t_list	*second;

	if (!*a)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	t_list	*second;

	if (!*b)
		return ;
	second = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*curr;

	if (!*b)
		return ;
	curr = *b;
	*b = curr->next;
	curr->next = *a;
	*a = curr;
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	t_list	*curr;

	if (!a)
		return ;
	curr = *a;
	*a = curr->next;
	curr->next = *b;
	*b = curr;
	write(1, "pb\n", 3);
}

void	ra(t_list **a)
{
	t_list	*curr;
	t_list	*temp;

	if (!*a)
		return ;
	curr = *a;
	temp = *a;
	*a = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*curr;
	t_list	*temp;

	if (!*b)
		return ;
	curr = *b;
	temp = *b;
	*b = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **a ,t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rra(t_list **a)
{
	t_list	*curr;
	t_list	*before_last;

	curr = *a;
	before_last = *a;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *a;
	*a = curr;
	before_last->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*curr;
	t_list	*before_last;

	curr = *b;
	before_last = *b;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *b;
	*b = curr;
	before_last->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
