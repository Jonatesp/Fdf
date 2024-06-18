/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_print_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:15:08 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/01 14:56:36 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_all_quarters2(int *p, int *d, t_data img, t_map m)
{
	int	color;

	color = ft_color(p);
	if (d[1] != 0)
		ft_middle_quarters(p, d, img, m);
	else
	{
		while (p[0] != p[2])
		{
			ft_putpxl(&img, p, m);
			p[0]--;
			p[4] = p[4] - color;
		}
	}
}

void	ft_first_octant(int *p, int *d, t_data img, t_map m)
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
		p[0]++;
		e = e - d[1];
		if (e < 0)
		{
			p[1]++;
			e = e + d[0];
		}
	}
}

void	ft_second_octant(int *p, int *d, t_data img, t_map m)
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
		e = e - d[0];
		if (e < 0)
		{
			p[0]++;
			e = e + d[1];
		}
	}
}

void	ft_eighth_octant(int *p, int *d, t_data img, t_map m)
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
		p[0]++;
		e = e + d[1];
		if (e < 0)
		{
			p[1]--;
			e = e + d[0];
		}
	}
}

void	ft_seventh_octant(int *p, int *d, t_data img, t_map m)
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
		e = e + d[0];
		if (e > 0)
		{
			p[0]++;
			e = e + d[1];
		}
	}
}
