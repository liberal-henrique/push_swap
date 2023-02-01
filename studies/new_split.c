/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:16:42 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/01 16:49:07 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	count_words(char *str, char delim)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delim && (str[i + 1] == delim || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}



void	do_split(char **new_string, const char *s, char delimiter)
{
	int	x;
	int	y;
	int	letter;

	x = 0;
	letter = 0;
	while(s[x])
	{
		if (s[x] == delimiter)
			x++;
		else
		{
			y = 0;
			while (s[x + y] != delimiter && s[x + y])
				y++;
			new_string[letter++] = malloc(sizeof(char) * (y + 1));
			if (!new_string)
				return (NULL);
			create_str(new_string[letter], s + l, delimiter);
			if (s[x + y] == '\0')
				break ;
			l = l + j;
		}
	}
}

char    **ft_split(const char *s, char c)
{
    char	**new_string;
    char	*str;
    int		index_str;
	int		start;
    int		i;


    new_string = NULL;
    str = (char *)s;
    i = 0;
    index_str = 0;
    new_string = malloc(sizeof(char *) * (count_words(str, c) + 1));
    do_split(new_string, s, delimiter);
    return (new_string);
}
int	main(void)
{
	char	str[] = "    Luiz Henrique Liberal de Souza";
	char	**result;
	int		i = 0;
	int		j = 0;


	result = ft_split(str, 32);
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			printf("%c", result[i][j]);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
