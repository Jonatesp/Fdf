/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:19:11 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:29:46 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *str, char c)
{
	int	i;
	int	count;
	int	bool;

	i = 0;
	count = 0;
	bool = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (bool == 1)
			{
				count++;
				bool = 0;
			}
		}
		else
			bool = 1;
		i++;
	}
	if (bool == 1)
		count++;
	return (count);
}

static int	ft_ccount(char const *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

static char	**ft_free(char **res, int j)
{
	while (--j >= 0)
		free(res[j]);
	free(res);
	return (NULL);
}

static char	**ft_split2(char const *s, char c, char **res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		res[j] = malloc(sizeof(char) * (ft_ccount(s, c, i) + 1));
		if (!res[j])
			return (ft_free(res, j));
		k = 0;
		while (s[i] != c && s[i])
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *str, char c)
{
	char	**res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_wcount(str, c) + 1));
	if (!res)
		return (NULL);
	return (ft_split2(str, c, res));
}
