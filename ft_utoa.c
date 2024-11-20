/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:50:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/20 14:38:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Converts a given integer to a string
		ARGS:
			n: Integer to be converted to string
	IN:
		n:	INT_MIN <= n <= INT_MAX
	OUT:
		normal:
			Returns an integer converted to a string
		memory allocation failure:
			return NULL

*/

#include "libft.h"

// Return the number of digits
static size_t	_count_digits(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/**
 * @brief Convert unsigned int to string
 * 
 * @param n			: Number to be converted
 * @return char* 
 */
char	*ft_utoa(unsigned int n)
{
	char			*s;
	size_t			len;

	if (n == 0)
		return (ft_strdup("0"));
	len = _count_digits(n);
	s = ft_calloc((len + 1) * sizeof(char), 1);
	if (!s)
		return (NULL);
	while (n > 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
