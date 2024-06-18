/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_print_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:30:51 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/01 15:39:19 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fourth_octant(int *p, int *d, t_data img, t_map m)
{
	int	e;
	int	color;

	color = ft_color(p);
	e = d[0];
	d[0] = d[0] * 2;
	d[1] = d[1] * 2;
	while (p[0] != p[2])
	{
		ft_putpxl(&img, p, m);
		p[4] = p[4] - color;
		p[0]--;
		e = e + d[1];
		if (e >= 0)
		{
			p[1]++;
			e = e + d[0];
		}
	}
}

void	ft_third_octant(int *p, int *d, t_data img, t_map m)
{
	int	e;
	int	color;

	color = ft_color(p);
	e = d[1];
	d[1] = e * 2;
	d[0] = d[0] * 2;
	while (p[1] != p[3])
	{
		ft_putpxl(&img, p, m);
		p[4] = p[4] - color;
		p[1]++;
		e = e + d[0];
		if (e <= 0)
		{
			p[0]--;
			e = e + d[1];
		}
	}
}

void	ft_fifth_octant(int *p, int *d, t_data img, t_map m)
{
	int	e;
	int	color;

	color = ft_color(p);
	e = d[0];
	d[0] = e * 2;
	d[1] = d[1] * 2;
	while (p[0] != p[2])
	{
		ft_putpxl(&img, p, m);
		p[4] = p[4] - color;
		p[0]--;
		e = e - d[1];
		if (e >= 0)
		{
			p[1]--;
			e = e + d[0];
		}
	}
}

void	ft_sixth_octant(int *p, int *d, t_data img, t_map m)
{
	int	e;
	int	color;

	color = ft_color(p);
	e = d[1];
	d[1] = e * 2;
	d[0] = d[0] * 2;
	while (p[1] != p[3])
	{
		ft_putpxl(&img, p, m);
		p[4] = p[4] - color;
		p[1]--;
		e = e - d[0];
		if (e >= 0)
		{
			p[0]--;
			e = e + d[1];
		}
	}
}

int	ft_color(int *p)
{
	int	dist[2];
	int	color;
	int	*diff;

	dist[0] = p[2] - p[0];
	dist[1] = p[3] - p[1];
	if (dist[0] < 0)
		dist[0] = -dist[0];
	if (dist[1] < 0)
		dist[1] = -dist[1];
	if (dist[1] > dist[0])
		dist[0] = dist[1];
	diff = ft_color_utils(p);
	color = (diff[0] / dist[0]) * 65536;
	color = color + (diff[1] / dist[0]) * 256;
	color = color + (diff[2] / dist[0]);
	free(diff);
	return (color);
}
