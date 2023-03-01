// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   split.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/18 17:55:36 by lliberal          #+#    #+#             */
// /*   Updated: 2023/02/01 17:36:34 by lliberal         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

// static char	**split_recursive(char **result, char *str, int cnt_strings, char c)
// {
// 	int		index;
// 	char	*keep_parts;

// 	index = 0;
// 	keep_parts = NULL;
// 	while (*str == c)
// 		str++;
// 	while (str[index] != c && str[index])
// 		index++;
// 	if (index > 0)
// 		keep_parts = malloc(sizeof(char) * (index + 1));
// 	index = 0;
// 	while (keep_parts && *str != c && *str)
// 		keep_parts[index++] = *str++;
// 	if (*str == c)
// 		keep_parts[index] = '\0';
// 	if (keep_parts)
// 		result = split_recursive(result, str, cnt_strings + 1, c);
// 	else
// 		result = malloc(sizeof(char *) * (cnt_strings + 1));
// 	if (result)
// 		result[cnt_strings] = keep_parts;

// 	return (result);
// }

// char	**ft_split(char const *s, char c)
// {
// 	return (split_recursive(0, (char *)s, 0, c));
// }

// void	freeAll(char **result)
// {
// 	int	i;

// 	i = 0;
// 	while (result[i])
// 	{
// 		free(result[i]);
// 		i++;
// 	}
//     free(result);
// }

// int	main(void)
// {
// 	char str[] = "   Luiz  Henrique  Liberal";
// 	char **result;
// 	int i = 0;
// 	int j = 0;

// 	result = ft_split(str, 32);

// 	while (result[i])
//     {
//         j = 0;
//         while (result[i][j])
//         {
//             printf("%c", result[i][j]);
//             j++;
//         }
//         i++;
//         printf("\n");
//     }
// 	freeAll(result);
// 	return (0);
// }
// 0x602000000058 is located 0 bytes to the right of 8
#include <stdlib.h>
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

void	print_array_2d(char **arr_bidimensional)
{
	int	i;
	int	j;

	i = -1;
	while (arr_bidimensional[++i])
	{
		printf("%s", arr_bidimensional[i]);
	}
}

int main(int argc, char **argv)
{
	int	i = -1;
	int	j;
	int	flag = 0;
	char	**new;

	new = ft_split(argv[1], 32);
	print_array_2d(new);
	freeAll(new);
	return (0);
}
