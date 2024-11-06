/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:12:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:55:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Searches for the passed string with c and returns its location.
		ARGS:
			s:	string to be searched
			c:	Characters to search for (passed as ASCII digits)
	IN:
		s:	NULL or allocated memory.
		c:	0 <= c <= UCHAR_MAX
	OUT:
		normal:
			found c:
				return c address.
			not found c:
				return NULL
		s is NULL:
			return NULL
		c<0:
			not found -> return NULL
		127<c:
			not found -> return NULL
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s || c < 0 || 127 < c)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
