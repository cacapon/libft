/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 11:56:03 by ttsubo           ###   ########.fr       */
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

// static char	*_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = _strlen(s);
// 	while (i >= 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i--;
// 	}
// 	return (NULL);
// }

// setの文字だったら進める
// "tripouille   xxx", " x" -> "tripouille"
/*
	s1[0]	=	't'
	s1[1]	=	'r'
	s1[2]	=	'i'
	s1[3]	=	'p'
	s1[4]	=	'o'
	s1[5]	=	'u'
	s1[6]	=	'i'
	s1[7]	=	'l'
	s1[8]	=	'l'
	s1[9]	=	'e'
	s1[10]	=	' '
	s1[11]	=	' '
	s1[12]	=	' '
	s1[13]	=	'x'
	s1[14]	=	'x'
	s1[15]	=	'x'
	s1[16]	=	'\0'

	st(0) < ed(15) && _strchr(" x", s1[0](t)) -> F
		st = 0
	ed(15) > st(0) && _strchr(" x", s1[15](x)) -> T
	ed(14) > st(0) && _strchr(" x", s1[14](x)) -> T
	ed(13) > st(0) && _strchr(" x", s1[13](x)) -> T
	ed(12) > st(0) && _strchr(" x", s1[12]( )) -> T
	ed(11) > st(0) && _strchr(" x", s1[11]( )) -> T
	ed(10) > st(0) && _strchr(" x", s1[10]( )) -> T
	ed(9)  > st(0) && _strchr(" x", s1[9] (e)) -> F
		ed = 9
	trim_str = malloc(0 + 9 + 1) 9文字+終端

*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		ed; // 15
	char	*trim_str;

	if (s1 == NULL || *s1 == '\0' || set == NULL || *set == '\0')
		return (NULL);
	st = 0;
	ed = _strlen(s1);
	while (st < ed && _strchr(set, s1[st]) != NULL)
		st++;
	while (ed > st && _strchr(set, s1[ed]) != NULL)
		ed--;
	trim_str = malloc(ed - st + 1);
	if (trim_str == NULL)
		return (NULL);
	_strlcpy(trim_str, s1 + st, ed - st + 1);
	return (trim_str);
}
