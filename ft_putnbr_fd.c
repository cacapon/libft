/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:40:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Writes the number to the file descriptor
		ARGS:
			n: integer to write
			fd:	file descriptor
	IN:
		n:	INT_MIN <= n <= INT_MAX
		fd:	INT_MIN <= n <= INT_MAX
	OUT:
		No return value.
		n is written to the file specified in fd.		
		
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char *s;
	
	s = ft_itoa(n);
	ft_putstr_fd(s,fd);
}
