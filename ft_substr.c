/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:51 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 11:22:23 by ttsubo           ###   ########.fr       */
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

static size_t	_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	copied;

	copied = 0;
	if (dstsize == 0)
		return (_strlen(src));
	while (copied < dstsize - 1 && *src)
	{
		*dst++ = *src++;
		copied++;
	}
	*dst = '\0';
	return (copied + _strlen(src));
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

static char	*_strdup(const char *s1)
{
	size_t	l;
	char	*d;

	if (s1 == NULL)
		return (NULL);
	l = _strlen(s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	return ((char *)_memcpy(d, s1, l + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = _strlen(s);
	if (start >= s_len)
		return _strdup("");
	if (start + len >= s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	_strlcpy(sub, s + start, len + 1);
	return (sub);
}
