/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:53:55 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:20:01 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_add_front(t_list **begin_list, t_list *new)
{
	t_list	*temp;

	temp = *begin_list;
	if (new)
	{
		if (*begin_list)
		{
			temp->prev = new;
			new->next = *begin_list;
		}
		*begin_list = new;
	}
}
