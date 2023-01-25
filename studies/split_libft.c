/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:51:12 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/23 16:52:19 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

int	word_count(const char *sr, char set)
{
	int	j;
	int	word;

	j = 0;
	word = 0;
	while (sr[j] != '\0')
	{
		if ((sr[j] != set) && ((sr[j + 1] == set) || (sr[j + 1] == '\0')))
		{
			word++;
		}
		j++;
	}
	return (word);
}

void	add_split(char **dst, const char *string, char set)
{
	int	l;
	int	j;
	int	letter;

	l = 0;
	letter = 0;
	while (string[l] != '\0')
	{
		if (string[l] == (char)set)
			l++;
		else
		{
			j = 0;
			while (string[l + j] != (char)set && string[j + l] != '\0')
				j++;
			dst[letter] = (char *) malloc (sizeof(char) * (j + 1));
			if (!dst[letter])
				return ;
			write_word(dst[letter], string + l, set);
			if (string[j + l] == '\0')
				break ;
			l = l + j;
			letter++;
		}
	}
}

char	**ft_split(char const *s, char set)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, set);
	res = (char **) malloc (sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	add_split(res, s, set);
	return (res);
}

int	main(void)
{
    char str[] = "ab   cd    e     ";
    char **result;

    result = ft_split(str, 32);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            printf("%c", result[i][j]);
        }
		printf("\n");
    }

    return (0);
}
