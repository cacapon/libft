/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:59 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 19:32:21 by ttsubo           ###   ########.fr       */
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

static size_t	_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = _strlen(dst);
	if (l >= dstsize)
		l = dstsize;
	if (l == dstsize)
		return (l + _strlen(src));
	return (l + _strlcpy(dst + l, src, dstsize - l));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (new_str == NULL)
		return (NULL);
	_strlcpy(new_str, s1, s1_len + 1);
	_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}
