/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 11:08:05 by ttsubo           ###   ########.fr       */
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

// Reason for “ed - st + 2”:
// 		ed is index and +2 to reserve space for 0.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	ed;
	char	*trim_str;

	if (s1 == NULL || *s1 == '\0')
		return (ft_strdup(""));
	if (set == NULL || *set == '\0')
		return (ft_strdup(s1));
	st = 0;
	ed = ft_strlen((char *)s1) - 1;
	while (st <= ed && ft_strchr(set, s1[st]) != NULL)
		st++;
	while (ed >= st && ft_strchr(set, s1[ed]) != NULL)
		ed--;
	if (st > ed)
		return (ft_strdup(""));
	trim_str = malloc(ed - st + 2);
	if (trim_str == NULL)
		return (NULL);
	ft_strlcpy(trim_str, s1 + st, ed - st + 2);
	return (trim_str);
}
