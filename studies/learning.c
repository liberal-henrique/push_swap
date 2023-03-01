/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:15:31 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/09 11:17:21 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}					t_node;

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
}

int		list_sorted(t_node **root)
{
	t_node	*curr;

	curr = *root;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	count_size(t_node	*root)
{
	t_node	*curr;
	int	i;

	i = 0;
	curr = root;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	curr = *root;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = value;
	if (*root == NULL)
	{
		new_node->next = *root;
		*root = new_node;
		return ;
	}
	if (curr->content == value)
		deallocate(root, 1);
	while (curr->next)
	{
		if (curr->content == value)
			deallocate(root, 1);
		curr = curr->next;
	}
	if (curr->content == value)
		deallocate(root, 1);
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
			break;
		}
		printf("[*][%ld]->", (long int)curr->content);
		curr = curr->next;
	}
}

long int	ft_atoi_check_numbers(const char *str, t_node *t_list_a)
{
	int		i;
	int		sign;
	int		flag;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	flag = 0;
	ft_isnum(str, t_list_a);
	if (ft_strncmp("-2147483648", str, 11) == 1)
		flag = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > 2147483648 && flag != 1)
			deallocate(&t_list_a, 1);
		i++;
	}
	return (res * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char )s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char )s1[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%i\n", ft_strncmp("-2147483648", "2147483648", 11));
	return (0);
}

// int	ft_atoi_check_numbers(const char *str, t_node *t_list_a)
// {
// 	int		i;
// 	int		sign;
// 	long int	res;

// 	i = 0;
// 	sign = 1;
// 	res = 0;
// 	while (str[i++])
// 	{
// 		if (str[i] == '-' || str[i] == '+')
// 			i++;
// 		if (str[i] >= 9 && str[i] <= 0)
// 			deallocate(&t_list_a, 1);
// 	}
// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + str[i] - '0';
// 		if (res >= 2147483648)
// 			deallocate(&t_list_a, 1);
// 		i++;
// 	}
// 	return (res * sign);
// }

// void	insert_end(t_node **root, int value)
// {
// 	t_node	*new_node;
// 	t_node	*curr;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (new_node == NULL)
// 		return ;
// 	new_node->content = value;
// 	new_node->next = NULL;
// 	if (*root == NULL)
// 	{
// 		new_node->next = *root;
// 		*root = new_node;
// 		return ;
// 	}
// 	curr = *root;
// 	while (curr->next)
// 	{
// 		curr = curr->next;
// 	}
// 	curr->next = new_node;

// }

// void	printList(t_node *root)
// {
// 	t_node	*curr;

// 	curr = root;
// 	while (curr != NULL)
// 	{
// 		if (curr->next == NULL)
// 		{
// 			printf("[*][%ld]", (long int)curr->content);
// 			break;
// 		}
// 		printf("[*][%ld]->", (long int)curr->content);
// 		curr = curr->next;
// 	}
// }

// int main(int argc, char **argv)
// {
//     int i = 0;
//     int number;
//     t_node  *t_list_a = NULL;

//     while (argv[++i])
//     {
//         insert_end(&t_list_a, ft_atoi_check_numbers(argv[i], t_list_a));
//     }

//     //insert_end(&t_list_a, 1);
//     printList(t_list_a);
//     deallocate(&t_list_a, 0);
//     return 0;
// }
// min int -2147483648
