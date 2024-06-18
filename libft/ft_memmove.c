/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:34 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:32:06 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*str2;

	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (str2 < str)
		while (++i <= n)
			str[n - i] = str2[n - i];
	else
		while (n-- > 0)
			*(str++) = *(str2++);
	return (dest);
}
