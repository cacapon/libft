/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/03 18:33:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// msul base.
static size_t	_strnlen(char *s, size_t n)
{
	const char	*p;

	p = ft_memchr(s, 0, n);
	if (p)
		return (p - s);
	else
		return (n);
}

// msul base.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = _strnlen(dst, dstsize);
	if (l == dstsize)
		return (l + ft_strlen(src));
	return (l + ft_strlcpy(dst + l, src, dstsize - l));
}
