/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:31:28 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/25 16:00:35 by lliberal         ###   ########.fr       */
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

static char	**split_recursive(char **result, char *str, int cnt_strings, char c)
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
		result = split_recursive(result, str, cnt_strings + 1, c);
	else
		result = malloc(sizeof(char *) * (cnt_strings + 1));
	if (result)
		result[cnt_strings] = keep_parts;
	free(keep_parts);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	return (split_recursive(0, (char *)s, 0, c));
}
