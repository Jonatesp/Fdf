/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:37:18 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/11 16:19:08 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_list	*ft_elem(char *line, int posX, int posY, int *j)
{
	int	pos_z;
	int	color;

	color = 16777215;
	while (line[j[0]] == ' ')
		j[0]++;
	pos_z = ft_atoi(line, j[0]);
	while (ft_isdigit(line[j[0]]) || line[j[0]] == '-')
		j[0]++;
	if (line[j[0]] == ',')
	{
		j[0] = j[0] + 3;
		color = ft_hexatoi(line, j[0]);
		while (ft_isalnum(line[j[0]]))
			j[0]++;
	}
	return (ft_list_create_elem(pos_z, color, posX, posY));
}

void	ft_error_checker(char *l, t_list **bgnl)
{
	int	i;

	i = 0;
	if (l && !l[i])
	{
		free(bgnl);
		free(l);
		exit(0);
	}
	while (l[i])
	{
		if (!(l[i] >= 48 && l[i] <= 57) && !(l[i] == '-') && !(l[i] == ',')
			&& !(l[i] >= 65 && l[i] <= 70) && !(l[i] >= 97 && l[i] <= 102)
			&& !(l[i] == 'x') && !(l[i] == 'X') && !(l[i] == ' ')
			&& !(l[i] == '\n'))
		{
			free(bgnl);
			free(l);
			exit(0);
		}
		i++;
	}
}

void	ft_parse_file(int fd, t_list **bgnl)
{
	t_list	*list;
	char	*line;
	int		*j;

	j = malloc(sizeof(int) * 3);
	if (!j)
		return ;
	j[1] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		j[0] = 0;
		j[2] = 0;
		ft_error_checker(line, bgnl);
		list = ft_parse_file_utils(j, line, bgnl, list);
		j[1]++;
		free(line);
	}
	free(line);
	free(j);
}

t_list	*ft_parse_file_utils(int *j, char *line, t_list **bgnl, t_list *list)
{
	t_list	*tmp;

	while (line[j[0]] && line[j[0]] != '\n')
	{
		while (line[j[0]] == ' ')
			j[0]++;
		if (!line[j[0]])
			break ;
		if (j[1] == 0 && j[2] == 0)
		{
			list = ft_elem(line, j[2] + 1, j[1] + 1, j);
			*bgnl = list;
		}
		else
		{
			tmp = list;
			list = ft_elem(line, j[2] + 1, j[1] + 1, j);
			list->prev = tmp;
			tmp->next = list;
		}
		j[2]++;
	}
	return (list);
}

void	ft_clear_list(t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(begin_list);
}
