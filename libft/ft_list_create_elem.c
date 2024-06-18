/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:45:40 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/01 15:12:38 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_create_elem(int value, int color, int pos_x, int pos_y)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!(elem))
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->value = value;
	elem->color = color;
	elem->pos_x = pos_x;
	elem->pos_y = pos_y;
	return (elem);
}
