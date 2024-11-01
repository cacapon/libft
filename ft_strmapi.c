/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:21:04 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 20:46:31 by ttsubo           ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	new_s = _strdup(s);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
