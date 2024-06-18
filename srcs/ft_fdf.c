/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:53:30 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/03 15:21:44 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_puterror(int error)
{
	if (error == 0)
		ft_putstr_fd("Correct usage is : ./fdf [valid .fdf file path]\n", 2);
	else if (error == 1)
		ft_putstr_fd("Invalid file path\n", 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**bgnl;
	int		fd;

	if (argc != 2)
		return (ft_puterror(0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_puterror(1));
	bgnl = malloc(sizeof(t_list));
	if (!bgnl)
		return (0);
	ft_parse_file(fd, bgnl);
	close(fd);
	ft_create_image(bgnl);
	ft_clear_list(bgnl);
	return (0);
}
