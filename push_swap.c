/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/01 19:49:10 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./push_swap.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct s_node
{
	int				content;
	int				size_a;
	int				size_b;
	struct s_node	*next;
}					t_node;

void		insert_end(t_node **root, int value);
void		deallocate(t_node **root, int message);
char		write_word(char *dest, const char *from, char set);
char		**ft_split(char const *s, char c);
int			word_count(const char *sr, char delimiter);
void		add_split(char **dst, const char *string, char delimiter);
void		freeAll(char **result);
t_node		*initialize_list(char **argv, t_node *t_list_a);
void		print_array_2d(char **arr_bidimensional);
t_node		*ft_split_create_str(t_node *t_list_a, char *argv, char delimiter);
void		printList(t_node *root);
int			list_sorted(t_node **root);
int			count_items(t_node *root);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isnum_compare(const char *str, t_node *t_list_a);
long int	ft_atoi_check_numbers(const char *str, t_node *t_list_a);

int	main(int argc, char **argv)
{
	t_node	*t_list_a;

	t_list_a = NULL;
	if (argc < 2)
		return (0);
	t_list_a = initialize_list(argv + 1, t_list_a);
	if (list_sorted(&t_list_a) == 1 && count_items(t_list_a) > 1)
		deallocate(&t_list_a, 1);
	printList(t_list_a);
	deallocate(&t_list_a, 0);
	return (0);
}

int	list_sorted(t_node **root)
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

int	count_items(t_node	*root)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = root;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

t_node	*initialize_list(char **argv, t_node *t_list_a)
{
	int		i;
	int		j;
	int		flag;
	t_node	*new_node;

	i = -1;
	new_node = NULL;
	while (argv[++i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j++])
		{
			if ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
			{
				flag = 1;
				new_node = ft_split_create_str(new_node, argv[i], argv[i][j]);
				break ;
			}
		}
		if (flag == 0)
			insert_end(&new_node, ft_atoi_check_numbers(argv[i], t_list_a));
	}
	return (new_node);
}

t_node	*ft_split_create_str(t_node *t_list_a, char *argv, char delimiter)
{
	char	**new_node;
	int		i;

	i = -1;
	new_node = ft_split(argv, delimiter);
	while (new_node[++i])
		insert_end(&t_list_a, ft_atoi_check_numbers(new_node[i], t_list_a));
	freeAll(new_node);
	return (t_list_a);
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

int	ft_isnum_compare(const char *str, t_node *t_list_a)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if ((str[i] > '9' || str[i] < '0'))
			deallocate(&t_list_a, 1);
	}
	if (ft_strncmp("-2147483648", str, 11) == 1)
		return (1);
	return (0);
}

long int	ft_atoi_check_numbers(const char *str, t_node *t_list_a)
{
	int			i;
	int			sign;
	int			flag;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	flag = ft_isnum_compare(str, t_list_a);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res >= 2147483648 && flag != 1)
			deallocate(&t_list_a, 1);
		i++;
	}
	return (res * sign);
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
			printf("\n");
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
		exit (write(1, "errorDeallo\n", 12));
}

char	write_word(char *dest, const char *from, char set)
{
	int	i;

	i = 0;
	while (from[i] != '\0')
	{
		if (from[i] != set)
			dest[i] = from[i];
		if (from[i] == set)
			break ;
		i++;
	}
	dest[i] = '\0';
	return (*dest);
}

int	word_count(const char *sr, char del)
{
	int	j;
	int	word;

	j = 0;
	word = 0;
	while (sr[j])
	{
		if (sr[j] != del && ((sr[j + 1] == del) || (sr[j + 1] == '\0')))
			word++;
		j++;
	}
	return (word);
}

void	add_split(char **dst, const char *string, char delimiter)
{
	int	l;
	int	j;
	int	letter;

	l = 0;
	letter = 0;
	while (string[l])
	{
		if (string[l] == delimiter)
			l++;
		else
		{
			j = 0;
			while (string[l + j] != delimiter && string[j + l])
				j++;
			dst[letter] = malloc (sizeof(char) * (j + 1));
			if (!dst[letter])
				return ;
			write_word(dst[letter], string + l, delimiter);
			if (string[j + l] == '\0')
				break ;
			l = l + j;
			letter++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = malloc (sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	add_split(res, s, c);
	return (res);
}

void	freeAll(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free (result);
}

void	print_array_2d(char **arr_bidimensional)
{
	int	i;

	i = -1;
	while (arr_bidimensional[++i])
		printf("%s", arr_bidimensional[i]);
}
