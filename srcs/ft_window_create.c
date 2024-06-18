/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:41:38 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/11 16:16:21 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_wclose(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_clear_list(vars->bgnl);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	ft_create_image(t_list **bgnl)
{
	t_vars	vars;
	t_data	img;
	t_map	stats;
	int		*p;

	stats = ft_list_stats(bgnl);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, stats.win_l, stats.win_w, "fdf");
	img.img = mlx_new_image(vars.mlx, stats.win_l, stats.win_w);
	vars.img = img.img;
	vars.bgnl = bgnl;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	p = malloc(sizeof(int) * 6);
	if (!p)
		return ;
	ft_print_horizon(bgnl, img, stats, p);
	ft_print_vertical(bgnl, img, stats, p);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, ft_wclose, &vars);
	free(p);
	mlx_loop(vars.mlx);
}

int	ft_putpxl(t_data *d, int *p, t_map m)
{
	char	*dst;

	if (p[0] >= m.win_l || p[0] <= 0 || p[1] >= m.win_w || p[1] <= 0)
		return (0);
	dst = d->addr + (p[1] * d->line_length + p[0] * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = p[4];
	return (1);
}

void	ft_print_horizon(t_list **bgnl, t_data img, t_map m, int *p)
{
	t_list	*l;
	t_list	*t;

	l = *bgnl;
	p[0] = m.x_s + (m.x * l->pos_x) + (-m.x * l->pos_y);
	p[1] = m.y_s + (m.y * l->pos_x) + (m.y * l->pos_y) + (-m.y * l->value);
	p[4] = l->color;
	ft_putpxl(&img, p, m);
	t = l;
	l = l->next;
	while (l)
	{
		p[0] = m.x_s + (m.x * l->pos_x) + (-m.x * l->pos_y);
		p[1] = m.y_s + (m.y * l->pos_x) + (m.y * l->pos_y) + (-m.y * l->value);
		p[2] = m.x_s + (m.x * t->pos_x) + (-m.x * t->pos_y);
		p[3] = m.y_s + (m.y * t->pos_x) + (m.y * t->pos_y) + (-m.y * t->value);
		p[4] = l->color;
		p[5] = t->color;
		if (l->pos_x != 1)
			ft_print_vector(p, img, m);
		t = l;
		l = l->next;
	}
}

void	ft_print_vertical(t_list **bgnl, t_data img, t_map m, int *p)
{
	t_list	*l;
	t_list	*t;

	l = *bgnl;
	p[0] = m.x_s + (m.x * l->pos_x) + (-m.x * l->pos_y);
	p[1] = m.y_s + (m.y * l->pos_x) + (m.y * l->pos_y) + (-m.y * l->value);
	t = l;
	l = l->next;
	while (t->pos_y < m.y_max)
	{
		l = t;
		while (!(l->pos_y != t->pos_y && l->pos_x == t->pos_x))
			l = l->next;
		p[0] = m.x_s + (m.x * l->pos_x) + (-m.x * l->pos_y);
		p[1] = m.y_s + (m.y * l->pos_x) + (m.y * l->pos_y) + (-m.y * l->value);
		p[2] = m.x_s + (m.x * t->pos_x) + (-m.x * t->pos_y);
		p[3] = m.y_s + (m.y * t->pos_x) + (m.y * t->pos_y) + (-m.y * t->value);
		p[4] = l->color;
		p[5] = t->color;
		ft_print_vector(p, img, m);
		t = t->next;
	}
}
