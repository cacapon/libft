/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:44:03 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 11:06:55 by ttsubo           ###   ########.fr       */
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

// This was created with reference to the code
// excluding the musl GNUC optimization.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (s == d)
		return (d);
	if ((uintptr_t)s - (uintptr_t)d - len <= -2 * len)
		return (ft_memcpy(d, s, len));
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
