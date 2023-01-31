/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:16:42 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/31 18:29:36 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//"a  b  c" --> "abc"

char	**ft_split(char const *s)
{
	char	**new_string;
	char	*str;
	int		i;

	str = s;
	new_string = NULL;
	while (str[i])
	{
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		while (*str != 32 || (*str <= 9 && *str >= 13))
			i++;
		if (i > 0)
		{
			new_string = malloc(size(char) * (i + 1));
		}

	}
}
