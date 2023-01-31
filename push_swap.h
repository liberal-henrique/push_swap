/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:10:04 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/31 11:59:02 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}					t_node;

size_t	ft_strlen(const char *a);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
void	insert_end(t_node **root, int value);
t_node	*check_spaces(char **argv, t_node *t_list_a);
int		ft_intermedia(char *argv, int delimiter);
char	**ft_split(char const *s, char c);
void	deallocate(t_node **root);

#endif
