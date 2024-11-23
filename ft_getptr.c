/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/23 16:36:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ポインタを16進数形式の文字列に変換しdstに格納します。
 *
 * @param dst
 * @param ptr
 */
void	ft_getptr(char *dst, void *ptr, size_t dstsize)
{
	int			i;
	uintptr_t	address;

	if (!ptr)
	{
		if (dst)
			ft_strlcpy(dst, "0x0", dstsize);
		return ;
	}
	address = (uintptr_t)ptr;
	dst[0] = '0';
	dst[1] = 'x';
	i = (sizeof(address) * 2) - 1;
	while (i >= 0)
	{
		dst[2 + i] = "0123456789abcdef"[address & 0xF];
		address >>= 4;
		i--;
	}
	dst[2 + (sizeof(address) * 2)] = '\0';
}
