/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeanuts <mpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:58:37 by mpeanuts          #+#    #+#             */
/*   Updated: 2022/04/07 15:58:38 by mpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (len-- >= needle_len && *haystack != '\0')
	{
		if (*needle == *haystack)
		{
			i = 0;
			while (haystack[i] == needle[i] && needle[i] != '\0')
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
