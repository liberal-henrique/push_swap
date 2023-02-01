/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/01 18:05:24 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "./push_swap.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//	Aqui vamos receber os numeros:
//- converte-los em inteiros
//- checar se sao numeros
//- se ha espacos demasiados
//- se ha repetidos --> nesse caso, retornaremos um erro;
//- verificar se ja esta sorted (return Zero comandos para ordenar)

// 42 Norminette Highlighter

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}					t_node;

int			ft_atoi_check_numbers(const char *str, t_node *t_list_a);
void		insert_end(t_node **root, int value);
void		deallocate(t_node **root);
char	write_word(char *dest, const char *from, char set);
int	word_count(const char *sr, char delimiter);
void	add_split(char **dst, const char *string, char delimiter);
char		**ft_split(char const *s, char c);
void	freeAll(char **result);
t_node		*check_spaces(char **argv, t_node *t_list_a);
t_node		*ft_split_create_str(t_node *t_list_a, char *argv, char delimiter);
void		printList(t_node *root);

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
	printf("Stack: A "); printList(t_list_a);
	deallocate(t_list_a);
	return (0);
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
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;

}

void	deallocate(t_node *root)
{
	t_node	*curr;
	t_node	*temp;

	curr = root;
	while (curr->next != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(root);
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
		insert_end(&t_list_a, ft_atoi_check_numbers(str_temp[i], t_list_a));
	while (str_temp[i++])
		free(str_temp[i]);
	return (t_list_a);
}

t_node	*check_spaces(char **argv, t_node *t_list_a)
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
			insert_end(&t_list_a, ft_atoi_check_numbers(argv[i], t_list_a));
	}
	return (t_list_a);
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

int	word_count(const char *sr, char delimiter)
{
	int	j;
	int	word;

	j = 0;
	word = 0;
	while (sr[j])
	{
		if (sr[j] != delimiter && ((sr[j + 1] == delimiter) || (sr[j + 1] == '\0')))
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
    free(result);
}


//gcc -fsanitize=address count_words.c -g -o split_rec
