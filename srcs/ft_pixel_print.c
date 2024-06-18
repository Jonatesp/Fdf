/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:49:57 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/01 15:37:30 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_middle_quarters(int *p, int *d, t_data img, t_map m)
{
	if (d[1] > 0)
	{
		if (-d[0] >= d[1])
			ft_fourth_octant(p, d, img, m);
		else
			ft_third_octant(p, d, img, m);
	}
	else
	{
		if (d[0] <= d[1])
			ft_fifth_octant(p, d, img, m);
		else
			ft_sixth_octant(p, d, img, m);
	}
}

void	ft_firstlast_quarters(int *p, int *d, t_data img, t_map m)
{
	if (d[1] > 0)
	{
		if (d[0] >= d[1])
			ft_first_octant(p, d, img, m);
		else
			ft_second_octant(p, d, img, m);
	}
	else
	{
		if (d[0] >= -d[1])
			ft_eighth_octant(p, d, img, m);
		else
			ft_seventh_octant(p, d, img, m);
	}
}

void	ft_all_quarters(int *p, int *d, t_data img, t_map m)
{
	int	color;

	color = ft_color(p);
	if (d[0] > 0)
	{
		if (d[1] != 0)
			ft_firstlast_quarters(p, d, img, m);
		else
		{
			while (p[0] != p[2])
			{
				ft_putpxl(&img, p, m);
				p[0]++;
				p[4] = p[4] - color;
			}
		}
	}
	else
		ft_all_quarters2(p, d, img, m);
}

void	ft_print_vector(int *p, t_data img, t_map m)
{
	int	d[2];
	int	color;

	d[0] = p[2] - p[0];
	d[1] = p[3] - p[1];
	color = ft_color(p);
	if (d[0] != 0)
		ft_all_quarters(p, d, img, m);
	else
	{
		while (p[1] != p[2] && d[1] > 0)
		{
			ft_putpxl(&img, p, m);
			p[1]++;
			p[4] = p[4] - color;
		}
		while (p[1] != p[3] && d[1] < 0)
		{
			ft_putpxl(&img, p, m);
			p[1]--;
			p[4] = p[4] - color;
		}
	}
}
