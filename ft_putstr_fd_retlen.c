/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_retlen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/23 15:52:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes strings to file descriptors 
 * 
 * @param s 		: string to write
 * @param fd 		: file descriptor
 * @return size_t	: Return the number written.
 */
size_t	ft_putstr_fd_retlen(char *s, int fd)
{
	if (s == NULL)
		return (0);
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}
