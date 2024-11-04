/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:08:18 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/04 22:28:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*now_node;

	if (lst == NULL)
		return (NULL);
	now_node = lst;
	while (now_node->next != NULL)
		now_node = now_node->next;
	return (now_node);
}
