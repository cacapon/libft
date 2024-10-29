/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:59 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/29 16:07:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_strlen(const char *str)
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

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = _strlen(dst);
	if (l >= dstsize)
		l = dstsize;
	if (l == dstsize)
		return (l + _strlen(src));
	return (l + _strlcpy(dst + l, src, dstsize - l));
}

static char	*_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*d;

	i = 0;
	l = _strlen(s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	while (i < l)
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (_strdup(s2));
	if (!s2)
		return (_strdup(s1));
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	if (new_str == NULL)
		return (NULL);
	_strlcpy(new_str, s1, s1_len + 1);
	_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}
