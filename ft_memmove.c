/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:44:03 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/28 14:25:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s || d >= s + len)
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		i = len + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	return (dst);
}
