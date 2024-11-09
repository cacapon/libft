/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:38:47 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 13:02:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Allocates memory of the size obtained by multiplying Count and size.
		After allocating the memory, initialize the memory with 0.
		ARGS:
			count:	Number of memories to be allocated
			size:	Size of memory to be allocated
	IN:
		count:	0 <= count <= SIZE_T_MAX
		size:	0 <= size  <= SIZE_T_MAX
	OUT:
		normal:
			Returns memory allocated by size multiplied by count.
		failure:
			Return NULL
		0 byte memory ex: (n,0),(0,n),(0,0)
			The C specification requires that it 
			return either NULL or a valid pointer.
			This function returns NULL.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	_size;
	void	*_block;

	if (count == 0 || size == 0)
		return (NULL);
	if (size > SIZE_MAX / count)
		return (NULL);
	_size = count * size;
	_block = malloc(_size);
	if (!_block)
		return (NULL);
	ft_memset(_block, 0, _size);
	return (_block);
}
