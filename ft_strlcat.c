/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:59:27 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/28 16:15:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char		*odest;
	const char		*osrc;
	unsigned int	n;
	unsigned int	dlen;

	n = dstsize;
	odest = dst;
	osrc = src;
	while (n-- != 0 && *dst)
		dst++;
	dlen = dst - odest;
	n = dstsize - dlen;
	if (n-- == 0)
		return (dlen + _strlen(src));
	while (*src)
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
