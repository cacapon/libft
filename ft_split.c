/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:41:56 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 11:07:16 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		SUMMARY:
		ARGS:
	IN:
	OUT:
*/

#include "libft.h"

static size_t	_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static size_t	_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_result(char **result, size_t index)
{
	while (index > 0)
		free(result[--index]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	index;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((_wordcount(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[index] = (char *)malloc((_wordlen(s, c) + 1) * sizeof(char));
			if (!result[index])
				return (free_result(result, index));
			ft_strlcpy(result[index], s, _wordlen(s, c) + 1);
			index++;
			s += _wordlen(s, c);
		}
		else
			s++;
	}
	result[index] = NULL;
	return (result);
}
