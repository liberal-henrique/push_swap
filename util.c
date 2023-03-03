/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:31:28 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/03 18:14:21 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*dest;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = -1;
	j = -1;
	length = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * length + 1);
	if (dest == 0)
		return (0);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[++j] != '\0')
		dest[i++] = s2[j];
	dest[i] = '\0';
	return (dest);
}

int		ft_atoi(const char *str)
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

int		list_sorted(t_list **root)
{
	t_list	*curr;

	curr = *root;
	while (curr->next)
	{
		if (curr->x > curr->next->x)
			return (0);
		curr = curr->next;
	}
	return (1);
}
