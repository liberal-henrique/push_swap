/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:41:11 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/03 18:27:05 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	deallocate(t_list **root, int message)
{
	t_list	*temp;

	while (*root)
	{
		temp = (*root)->next;
		free(*root);
		*root = temp;
	}
	root = NULL;
	if (message == 1)
		exit (write(1, "errorDeallo\n", 12));
}
