/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:44:03 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:23:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Copying with overlap taken into account
		ARGS:
			dst: Area to hold the copied byte sequence
			src: Byte sequence to be copied
			len: Length to copy
	IN:
		dst:	NULL or allocated memory.
		src:	NULL or allocated memory.
		len:	0 <= len <= SIZE_T_MAX
	OUT:
		normal:
			src and dst are the same:
				return dst (Nothing to do.)
			no overrap:
				Memcpy and return value
			Overlap and dst is in front of src:
				Make a forward copy and return value
			Overlap and src is in front of dst.
				Make a backward copy and return value
		dst is NULL or src is NULL:
			Operation is not guaranteed due to undefined operation.
		dst.length < n or src.length < n:
			Operation is not guaranteed due to undefined operation.
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
