/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:33 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/03 16:03:43 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	ft_list_stats(t_list **bgnl)
{
	t_list	*list;
	t_map	stats;
	int		pos_z[2];

	list = *bgnl;
	pos_z[1] = 0;
	while (list->next)
	{
		if (list->value > pos_z[1])
			pos_z[1] = list->value;
		list = list->next;
	}
	pos_z[0] = pos_z[1];
	list = *bgnl;
	while (list->next)
	{
		if (list->value < pos_z[0])
			pos_z[0] = list->value;
		list = list->next;
	}
	stats.z_max = pos_z[1];
	stats.z_min = pos_z[0];
	stats = ft_list_stats_utils(stats, list);
	return (stats);
}

t_map	ft_list_stats_utils2(t_map m)
{
	if (m.y_max >= 200 || m.x_max >= 200)
	{
		m.x = 2;
		m.y = 1;
	}
	else if (m.y_max >= 80 || m.x_max >= 80)
	{
		m.x = 4;
		m.y = 2;
	}
	else if (m.y_max >= 30 || m.y_max >= 30)
	{
		m.x = 9;
		m.y = 6;
	}
	else
	{
		m.x = 15;
		m.y = 10;
	}
	return (m);
}

t_map	ft_list_stats_utils(t_map m, t_list *list)
{
	int	ratio;

	m.x_max = list->pos_x;
	m.y_max = list->pos_y;
	ratio = 300;
	m = ft_list_stats_utils2(m);
	m.win_l = m.x * (m.x_max + m.y_max) + ratio;
	m.win_w = m.y * ((m.z_max - m.z_min) + (m.y_max + m.x_max) / 2) + ratio;
	if (m.win_l > 1000)
		m.win_l = 1000;
	if (m.win_w > 800)
		m.win_w = 800;
	m.x_s = m.win_l / 2 - (m.x_max - m.y_max) * (m.x / 2);
	m.y_s = 20 + ((m.z_max - m.z_min) * m.y);
	if (m.x_s < 100)
		m.x_s = m.win_l / 2 - 200;
	if (m.y_s > m.win_w)
		m.y_s = 20 + ((m.z_max - m.z_min) * 3);
	if (m.y_max > 300)
		m.y_s = 50;
	return (m);
}

int	*ft_color_utils2(int *tab, char *tmp, int *i, int *p)
{
	int		*res;
	char	*color;

	i[0] = 0;
	color = ft_itohexa(p[5]);
	while (i[0] < 6)
	{
		tmp[0] = color[i[0]];
		tmp[1] = color[i[0] + 1];
		tab[i[1]++] = ft_hexatoi(tmp, 0);
		i[0] = i[0] + 2;
	}
	res = malloc(sizeof(int) * 3);
	if (!res)
		return (0);
	res[0] = tab[0] - tab[3];
	res[1] = tab[1] - tab[4];
	res[2] = tab[2] - tab[5];
	free(tab);
	free(tmp);
	free(color);
	return (res);
}

int	*ft_color_utils(int *p)
{
	char	*color;
	char	*tmp;
	int		*tab;
	int		i[2];

	color = ft_itohexa(p[4]);
	tmp = malloc(sizeof(char) * 2);
	if (!tmp)
		return (0);
	tab = malloc(sizeof(int) * 6);
	if (!tab)
		return (0);
	i[0] = 0;
	i[1] = 0;
	while (i[0] < 6)
	{
		tmp[0] = color[i[0]];
		tmp[1] = color[i[0] + 1];
		tab[i[1]++] = ft_hexatoi(tmp, 0);
		i[0] = i[0] + 2;
	}
	free(color);
	return (ft_color_utils2(tab, tmp, i, p));
}
