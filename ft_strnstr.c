/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:44:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/28 13:00:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_i;
	size_t	n_i;

	if (*needle == '\0')
		return ((char *)haystack);
	h_i = 0;
	while (haystack[h_i] && h_i < len)
	{
		n_i = 0;
		while (needle[n_i] && haystack[h_i + n_i] && (h_i + n_i) < len)
		{
			if (haystack[h_i + n_i] != needle[n_i])
				break ;
			n_i++;
		}
		if (needle[n_i] == '\0')
			return ((char *)&haystack[h_i]);
		h_i++;
	}
	return (NULL);
}
