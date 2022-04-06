#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_last;

	s_last = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			s_last = (char *)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		s_last = (char *)s;
	return (s_last);
}
