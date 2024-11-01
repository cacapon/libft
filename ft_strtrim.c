/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 17:37:00 by ttsubo           ###   ########.fr       */
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

static int	_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	ed;
	size_t	s1_len;
	size_t	set_len;
	char	*trim_str;

	if (s1 == NULL || *s1 == '\0' || set == NULL || *set == '\0')
		return (NULL);
	st = 0;
	s1_len = _strlen(s1);
	ed = s1_len;
	set_len = _strlen(set);
	while (st < ed && !_strncmp(&s1[st], set, set_len))
		st += set_len;
	while (ed > st && !_strncmp(&s1[ed - set_len], set, set_len))
		ed -= set_len;
	trim_str = malloc(ed - st + 1);
	if (trim_str == NULL)
		return (NULL);
	_strlcpy(trim_str, s1 + st, ed - st + 1);
	return (trim_str);
}
