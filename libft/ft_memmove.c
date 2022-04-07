/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeanuts <mpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:58:12 by mpeanuts          #+#    #+#             */
/*   Updated: 2022/04/07 15:58:13 by mpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (len == 0)
	{
		return (dst);
	}
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (--len != 0)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		return (dst);
	}
}
