/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:56:30 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/25 16:24:54 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}					t_node;

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	curr = *root;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	deallocate(t_node **root)
{
	t_node	*curr;
	t_node	*temp;

	curr = *root;
	while (curr->next != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*root = NULL;
}

void	insert_beginning(t_node **root, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->next = *root;
	*root = new_node;
}

void	insert_after(t_node *node, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->next = node->next;
	node->next = new_node;
}

void	insert_sorted(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	if (*root == NULL || (*root)->x >= value)
	{
		insert_beginning(root, value);
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
	{
		if (curr->next->x >= value)
		{
			insert_after(curr, value);
			return ;
		}
		curr = curr->next;
	}
	insert_after(curr, value);
}

void	remove_element(t_node **root, int value)
{
	t_node	*curr;
	t_node	*remove;

	if (*root == NULL)
		return ;
	if ((*root)->x == value)
	{
		remove = *root;
		*root = (*root)->next;
		free(remove);
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
	{
		if (curr->next->x == value)
		{
			remove = curr->next;
			curr->next = curr->next->next;
			free(remove);
			return ;
		}
		curr = curr->next;
	}
}

void	reverse(t_node **root)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*post;

	if ((*root) == NULL)
		return ;
	curr = *root;
	prev = NULL;
	while (curr->next != NULL)
	{
		post = curr->next;
		curr->next = prev;
		prev = curr;
		curr = post;
	}
	*root = prev;
}

int	counter(t_node *root)
{
	t_node	*curr;
	int		counter;

	curr = root;
	counter = 0;
	while (curr != NULL)
	{
		counter++;
		curr = curr->next;
	}
	return (counter);
}

int	counter_recursively(t_node *root)
{
	if (root == NULL)
		return (0);
	return (1 + counter_recursively(root->next));
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

char	*ft_strchr(const char *str, int c)
{
	char	valor;
	char	*sr;

	valor = c;
	sr = (char *)str;
	while (*sr)
	{
		if (*sr == valor)
			return (sr);
		sr++;
	}
	if (*sr == valor)
		return (sr);
	return (0);
}

char	*check_spaces_and_numbers(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= 9 || argv[i] <= 13) && argv[i] == 32)
		{

		}
		if (argv[i] < 48 || argv[i] > 57)
			return (0);
		i++;
	}
	return (argv);
}

int	main(int argc, char *argv[])
{
	t_node	*root;
	t_node	*curr;
	int		content;
	int		i;

	root = NULL;
	curr = root;
	i = 1;
	if (argc == 1)
		return (0);
	else
	{
		while (argv[i])
		{
			if (!check_spaces_and_numbers(argv[i]))
				exit(printf("%s\n", "error"));
			content = ft_atoi(argv[i]);
			insert_end(&root, content);
			i++;
		}
		i = 1;
		curr = root;
		while (curr != NULL)
		{
			printf("O input para o node %i : %d\n", i, curr->x);
			i++;
			curr = curr->next;
		}
		printf("Estao na linked list: %i\n", i - 1);
	}
	deallocate(&root);
	return (0);
}
