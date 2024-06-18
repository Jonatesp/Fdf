/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:06:18 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/09 20:37:58 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../srcs/gnl/get_next_line.h"

typedef struct s_map
{
	int	x_max;
	int	y_max;
	int	z_max;
	int	z_min;
	int	win_l;
	int	win_w;
	int	x;
	int	y;
	int	x_s;
	int	y_s;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	t_list	**bgnl;
}				t_vars;

int		ft_puterror(int error);

int		ft_wclose(int keycode, t_vars *vars);
void	ft_create_image(t_list **bgnl);
int		ft_putpxl(t_data *d, int *p, t_map m);

void	ft_print_horizon(t_list **bgnl, t_data img, t_map stats, int *p);
void	ft_print_vertical(t_list **bgnl, t_data img, t_map stats, int *p);

void	ft_parse_file(int fd, t_list **bgnl);
t_list	*ft_parse_file_utils(int *j, char *line, t_list **bgnl, t_list *list);
t_list	*ft_elem(char *line, int posX, int posY, int *j);
void	ft_clear_list(t_list **begin_list);
void	ft_error_checker(char *l, t_list **bgnl);

void	ft_middle_quarters(int *p, int *d, t_data img, t_map m);
void	ft_firstlast_quarters(int *p, int *d, t_data img, t_map m);
void	ft_all_quarters(int *p, int *d, t_data img, t_map m);
void	ft_print_vector(int *p, t_data img, t_map m);

void	ft_all_quarters2(int *p, int *d, t_data img, t_map m);
void	ft_first_octant(int *p, int *d, t_data img, t_map m);
void	ft_second_octant(int *p, int *d, t_data img, t_map m);
void	ft_eighth_octant(int *p, int *d, t_data img, t_map m);
void	ft_seventh_octant(int *p, int *d, t_data img, t_map m);

void	ft_fourth_octant(int *p, int *d, t_data img, t_map m);
void	ft_third_octant(int *p, int *d, t_data img, t_map m);
void	ft_fifth_octant(int *p, int *d, t_data img, t_map m);
void	ft_sixth_octant(int *p, int *d, t_data img, t_map m);
int		ft_color(int *p);

t_map	ft_list_stats(t_list **bgnl);
t_map	ft_list_stats_utils(t_map m, t_list *list);
t_map	ft_list_stats_utils2(t_map m);
int		*ft_color_utils(int	*p);
int		*ft_color_utils2(int *tab, char *tmp, int *i, int *p);

#endif