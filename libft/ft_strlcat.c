#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	n;

	dst_len = 0;
	if (dstsize)
	{
		n = dstsize;
		i = 0;
		j = 0;
		while (dst[i] != '\0' && dstsize--)
			i++;
		dst_len = i;
		while (i < n - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		if (j > 0)
			dst[i] = '\0';
	}
	return (ft_strlen(src) + dst_len);
}
