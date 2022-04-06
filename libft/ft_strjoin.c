#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (!s1 || !s2)
		return ("");
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
