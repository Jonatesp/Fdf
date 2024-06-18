/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:36:37 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 18:44:03 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del_back(t_list **begin_list, t_list *list)
{
	t_list	*ltmp;

	if (!list || !begin_list)
		return ;
	while (list->next)
	{
		ltmp = list;
		list = list->next;
	}
	ltmp->next = NULL;
	free(list);
}
