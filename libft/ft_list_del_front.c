/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:56:53 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 18:12:23 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del_front(t_list **begin_list, t_list *list)
{
	t_list	*temp;

	if (!list || !begin_list)
		return ;
	*begin_list = list->next;
	temp = *begin_list;
	if (temp)
		temp->prev = NULL;
	free(list);
}
