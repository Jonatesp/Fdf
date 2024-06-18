/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:44 by anbourge          #+#    #+#             */
/*   Updated: 2020/11/24 14:37:46 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp = (char *)dest;
	while (i < n)
	{
		*(char *)temp = *(char *)src;
		temp++;
		src++;
		i++;
	}
	return (dest);
}
