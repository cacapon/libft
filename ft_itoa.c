/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:50:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 20:18:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// (n <= 0)... True:1 False:0
static int	_numlen(int n)
{
	int	len;

	len = (n <= 0);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

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

	l = _strlen(s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	return ((char *)_memcpy(d, s1, l + 1));
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		num;

	num = n;
	if (n == 0)
		return (_strdup("0"));
	if (n == INT_MIN)
		return (_strdup("-2147483648"));
	len = _numlen(n);
	s = (char *)malloc(len + (n < 0));
	if (!s)
		return (NULL);
	s[len - (n >= 0)] = '\0';
	if (n < 0)
		num = -n;
	while (num)
	{
		s[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
