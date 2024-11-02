/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:00:38 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 13:09:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*d;

	if (s1 == NULL)
		return (NULL);
	l = (size_t)ft_strlen((char *)s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	return ((char *)ft_memcpy(d, s1, l + 1));
}
