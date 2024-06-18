/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:13:36 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:56:55 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_norminette(char *res)
{
	res[0] = '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		i;

	nb = n;
	i = ft_nblen(n);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (nb == 0)
		return (ft_norminette(res));
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (res);
}
