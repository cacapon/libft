/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:26:29 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 11:06:52 by ttsubo           ###   ########.fr       */
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

// This was created with the musl no conditions as a reference.
// ATTENTION:
// 	memcpy(NULL,NULL,3) will cause a segfault, unlike the standard mac library.
// 	Depending on the unit test, it may cause a crash error,
//	but we will not respond to it due to undefined behavior.
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
