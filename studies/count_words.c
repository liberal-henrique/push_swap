#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	char	str[] = "   Luiz  Henrique  Liberal";
	char	**word;
    int j = 0;
    int i = 0;

	word = ft_split(str, 32);
	while (word[i])
    {
        j = 0;
        while (word[i][j])
        {
            printf("%c", word[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
	freeAll(word);
	return (0);
}
