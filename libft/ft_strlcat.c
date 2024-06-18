/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:26:41 by anbourge          #+#    #+#             */
/*   Updated: 2020/11/21 17:52:56 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	i = 0;
	dst_size = 0;
	while (dst_size < size && dst[dst_size])
		dst_size++;
	if (size <= dst_size)
		return (size + src_size);
	while (size && (--size - dst_size) && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
