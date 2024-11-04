/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:02:00 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/04 22:06:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;
	t_list *now_node;

	if (lst == NULL)
		return (0);
	i = 1;
	now_node = lst;
	while (now_node->next != NULL)
	{
		i++;
		now_node = now_node->next;
	}
	return (i);
}