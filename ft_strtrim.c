/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/05 17:28:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO:trimでstartがendより大きい値になった時はその時点でから文字列を返したほうがいい
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
	trim_str = malloc(ed - st + 2);
	if (trim_str == NULL)
		return (NULL);
	ft_strlcpy(trim_str, s1 + st, ed - st + 2);
	return (trim_str);
}
