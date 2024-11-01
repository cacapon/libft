/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 11:51:46 by ttsubo           ###   ########.fr       */
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

static char	*_strdup(const char *s1)
{
	size_t	i;
	char	*d;

	if (s1 == NULL)
		return (NULL);
	d = malloc(_strlen(s1) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_i;
	size_t	trim_str_i;
	char	*trim_str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *set == '\0')
		return (_strdup(s1));
	trim_str = (char *)malloc(_strlen(s1) + 1);
	if (trim_str == NULL)
		return (NULL);
	s1_i = 0;
	trim_str_i = 0;
	while (s1[s1_i])
	{
		if (_strncmp(&s1[s1_i], set, _strlen(set)) == 0)
			s1_i += _strlen(set);
		else
			trim_str[trim_str_i++] = s1[s1_i++];
	}
	trim_str[trim_str_i] = '\0';
	return (trim_str);
}
