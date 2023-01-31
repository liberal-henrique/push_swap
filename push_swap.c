/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/31 12:37:12 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// int	ft_intermedia(char **argv, int delimiter)
// {
// 	char	**new_arr;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	new_arr = ft_split(**argv, delimiter);
// 	while (new_arr[i])
// 	{
// 		while (new_arr[i][j])
// 		{
// 			if (new_arr[i][j] < 48 || new_arr[i][j] > 57)
// 				exit (2);
// 		}
// 	}
// 	return (1);
// }

//	Aqui vamos receber os numeros:
//- converte-los em inteiros
//- checar se sao numeros
//- se ha espacos demasiados
//- se ha repetidos --> nesse caso, retornaremos um erro;
//- verificar se ja esta sorted (return Zero comandos para ordenar)

// if ((argv[i][j] >= 9 || argv[i][j] <= 13) && argv[i][j] == 32)
// 			{
// 				flag = ft_intermedia((char *)argv[i], argv[i][j]);
// 				break ;
// 			}

// 42 Norminette Highlighter

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}					t_node;

int			ft_atoi(const char *str);
void		insert_end(t_node **root, int value);
void		deallocate(t_node **root);
static char	**split_rcsv(char **result, char *str, int cnt_strings, char c);
char		**ft_split(char const *s, char c);
t_node		*check_spaces(char **argv, t_node *t_list_a);
t_node		*ft_split_create_str(t_node *t_list_a, char *argv, char delimiter);

int	main(int argc, char *argv[])
{
	t_node	*t_list_a;
	t_node	*curr;
	int		i;

	i = 1;
	t_list_a = NULL;
	curr = t_list_a;
	if (argc < 2)
		return (0);
	t_list_a = check_spaces(argv + 1, t_list_a);
	return (0);
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
// "+1 +1 -3 -2"
int	ft_atoi_check_numbers(const char *str, t_node *t_list_a)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;

	while (str[i++])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= 9 && str[i] <= 0)
			deallocate(&t_list_a);
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > 2147483647 || res < -2147483648)
			deallocate(&t_list_a);
		i++;
	}
	return (res * sign);
}

t_node	*ft_split_create_str(t_node *t_list_a, char *argv, char delimiter)
{
	char	**str_temp;
	int		i;

	i = 0;
	str_temp = ft_split((char *) argv, delimiter);
	while (str_temp[i++])
		insert_end(&t_list_a, ft_atoi_check_numbers((str_temp[i], t_list_a));
	deallocate(&str_temp);
	return (t_list_a);
}

t_node *check_spaces(char **argv, t_node *t_list_a)
{
	int		i;
	int		j;
	int		flag;
	t_node	*new_node;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j++])
		{
			if ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
			{
				new_node = ft_split_create_str(new_node, argv[i], argv[i][j]);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			insert_end(&t_list_a, ft_atoi(argv[i], t_list_a));
	}
	return (t_list_a);
}
static char	**split_rcsv(char **result, char *str, int cnt_strings, char c)
{
	int		index;
	char	*keep_parts;

	index = 0;
	keep_parts = NULL;
	while (*str == c)
		str++;
	while (str[index] != c && str[index])
		index++;
	if (index > 0)
		keep_parts = malloc(sizeof(char) * (index + 1));
	index = 0;
	while (keep_parts && *str != c && *str)
		keep_parts[index++] = *str++;
	if (*str == c)
		keep_parts[index] = '\0';
	if (keep_parts)
		result = split_rcsv(result, str, cnt_strings + 1, c);
	else
		result = malloc(sizeof(char *) * (cnt_strings + 1));
	if (result)
		result[cnt_strings] = keep_parts;
	free(keep_parts);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	return (split_rcsv(0, (char *)s, 0, c));
}
