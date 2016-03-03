/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:30:59 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/18 23:23:43 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_save_map(char ***str, int x_max, int y_max)
{
	int		i;
	int		x;
	int		y;
	t_point *point;

	i = 0;
	x = 0;
	y = 0;
	point = malloc(sizeof(*point) * (y_max * x_max));
	while (i <= (x_max * y_max))
	{
		point[i].y = y;
		point[i].x = x;
		point[i].z = ft_atoi(str[y][x]);
		if (x >= x_max)
		{
			y++;
			x = 0;
		}
		else
			x++;
		i++;
	}
	ft_putendl("Parsing done!");
	return (point);
}

int		ft_check_map(char *line, int *x_max)
{
	int	i;
	int c;
	int	s;

	i = 0;
	c = 0;
	s = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			s++;
		else if (s != 0)
		{
			c++;
			s = 0;
		}
		i++;
	}
	if (*x_max != 0 && c != *x_max)
		ft_error(3);
	*x_max = c;
	return (0);
}

t_point		*ft_read_map(char *file, t_map *map)
{
	char	*line;
	int		i;
	char	**str[400000];
	int		fd;

	i = 0;
	map->x_max = 0;
	map->y_max = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(2);
	while ((get_next_line(fd, &line)))
	{
		ft_putendl(line);
		str[map->y_max] = ft_strsplit(line, ' ');
		ft_check_map(line, &map->x_max);
		map->y_max++;
	}
	printf("\nMAP INFO :\n x = %i | y = %d\n\n", map->x_max, map->y_max);
	return(ft_save_map(str, map->x_max, map->y_max));
}
