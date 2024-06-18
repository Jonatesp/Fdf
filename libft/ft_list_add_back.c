/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:38:58 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:27:23 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_add_back(t_list **begin_list, t_list *new)
{
	t_list	*last;
	t_list	*temp;

	if (*begin_list)
	{
		last = ft_list_last(*begin_list);
		last->next = new;
		temp = last->next;
		temp->prev = last;
	}
	else
		*begin_list = new;
}
