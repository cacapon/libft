/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:51 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/29 15:15:17 by ttsubo           ###   ########.fr       */
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

static void	*_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL || src == NULL)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

static size_t	_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;

	src_length = _strlen(src);
	if ((src_length >= dstsize))
	{
		if (dstsize > 0)
		{
			_memcpy(dst, src, dstsize);
			dst[dstsize - 1] = '\0';
		}
	}
	else
		_memcpy(dst, src, src_length + 1);
	return (src_length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = _strlen(s);
	if (start >= s_len)
		return (NULL);
	if (start + len >= s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	_strlcpy(sub, s, len);
	return (sub);
}
