/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:54:35 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 14:36:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Write c to len byte string b.
		ARGS:
			b:		Memory area to write
			c:		character (internally converted to unsigned char)
			len:	Length of writing c to memory
	IN:
		b:		NULL or allocated memory space.
		c:		0 <= c <= UCHAR_MAX
		len:	0 <= len <= SIZE_T_MAX
	OUT:
		normal:		return b (c already written)
		b is NULL:	return b (Nothing to do)
		c < 0:		return b (Nothing to do)
		255 < c:	return b (Nothing to do)
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	if (!b || c < 0 || UCHAR_MAX < c)
		return (b);
	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}
