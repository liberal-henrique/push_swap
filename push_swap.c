/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/25 17:32:38 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//here  I will develop

int	ft_intermedia(char *argv, int delimiter)
{
	char	**new_arr;

	new_arr = ft_split(*argv, delimiter);
	while (new_arr[i])
	{
		while (new_arr[i][j])
		{
			if (new_arr[i][j] < 48 || new_arr[i][j] > 57)
				exit ("error");
		}
	}
	return (1);
}

t_node	*check_spaces_and_numbers(char **argv, t_node *t_list_a)
{
	int		i;
	int		j;
	int		*content;
	int		flag;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 9 || argv[i][j] <= 13) && argv[i][j] == 32)
			{
				flag = ft_intermedia(argv[i], argv[i][j]);
				break ;
			}
			if (argv[i][j] < 48 || argv[i][j] > 57)
				exit("error");
			j++;
		}
		if (flag == 0)
			content = ft_atoi(argv[i]);
		i++;
	}
	return (t_list_a);
}

int	main(int argc, char *argv[])
{
	t_node	*t_list_a;
	t_node	*t_list_b;
	int		content;
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	else
	{
		while (argv[1])
		{
			t_list_a = check_spaces_and_numbers(*argv, t_list_a)

			insert_end(&root, content);
			i++;
		}
	}
	deallocate(&root);
	return (0);
}
