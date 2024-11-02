/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 12:31:10 by ttsubo           ###   ########.fr       */
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
		return ((size_t)_strlen(src));
	while (copied < dstsize - 1 && *src)
	{
		*dst++ = *src++;
		copied++;
	}
	*dst = '\0';
	return (copied + (size_t)_strlen(src));
}

static char	*_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		ed;
	char	*trim_str;

	if (s1 == NULL || *s1 == '\0' || set == NULL || *set == '\0')
		return (NULL);
	st = 0;
	ed = _strlen(s1) - 1;
	while (st <= ed && _strchr(set, s1[st]) != NULL)
		st++;
	while (ed >= st && _strchr(set, s1[ed]) != NULL)
		ed--;
	trim_str = malloc(ed - st + 2);
	if (trim_str == NULL)
		return (NULL);
	_strlcpy(trim_str, s1 + st, ed - st + 2);
	return (trim_str);
}
