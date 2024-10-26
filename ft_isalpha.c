/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:27:37 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/26 18:36:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int is_lower;
	int is_upper;

	is_lower = ('a' <= c && c <= 'z');
	is_upper = ('A' <= c && c <= 'Z');
	return (is_lower || is_upper);
}
