/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/29 16:13:42 by ttsubo           ###   ########.fr       */
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

//「malloc(3) を使ってメモリを割り当て、文字列の先頭と末尾から set に指定された文字を削除した s1 のコピーを返します。」
char *ft_strtrim(char const *s1, char const *set)
{
	char *trim_str;

	trim_str = _strdup(s1);
	if (trim_str == NULL)
		return (NULL);
	
}