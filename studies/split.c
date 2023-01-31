/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/31 17:49:57 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

int	main(void)
{
	char str[] = "ab cd e";
	char **result;
	int i = 0;
	int j = 0;

	result = ft_split(str, 32);
	

	printf("\n");
	free(result);
	return (0);
}
