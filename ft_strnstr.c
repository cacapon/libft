/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:44:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 11:07:55 by ttsubo           ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_i;
	size_t	l_i;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	b_i = 0;
	while (big[b_i] && b_i < len)
	{
		l_i = 0;
		while (little[l_i] && big[b_i + l_i] && (b_i + l_i) < len)
		{
			if (big[b_i + l_i] != little[l_i])
				break ;
			l_i++;
		}
		if (little[l_i] == '\0')
			return ((char *)&big[b_i]);
		b_i++;
	}
	return (NULL);
}
