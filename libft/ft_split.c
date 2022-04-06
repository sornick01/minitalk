#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			words++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (words);
}

static char	*get_word(const char **s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while ((*s)[i] != '\0' && (*s)[i] != c)
		i++;
	word = ft_substr(*s, 0, i);
	if (!word)
		return (NULL);
	(*s) = (*s) + i + 1;
	return (word);
}

static void	*free_mem(char ***tab, size_t	i)
{
	while (i >= 0)
	{
		free((*tab)[i]);
		i--;
	}
	free(*tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s != '\0' && i < words)
	{
		if (*s != c)
		{
			tab[i] = get_word(&s, c);
			if (!tab[i++])
				return (free_mem(&tab, i - 1));
		}
		else
			s++;
	}
	return (tab);
}
