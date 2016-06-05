/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:42:28 by lucas             #+#    #+#             */
/*   Updated: 2016/06/05 18:55:12 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_check_file(t_gen *gen)
{
	char	*line;
	char	**split;
	int 	fd;

	fd = open(gen->filename, O_RDONLY);
	gen->x = 0;
	gen->y = 0;
	while (get_next_line(fd, &line))
	{
		if (gen->y == 0)
			split = ft_strsplit(line, ' ');
		gen->y++;
		free(line);
	}
	while (split[gen->x])
		gen->x++;
	close(fd);
	ft_freetab(split);
}

void		ft_save_line(char *line, t_gen *gen)
{
	char	**split;
	int		i;

	i = 0;
	gen->map[gen->y] = malloc(sizeof(t_point*) * gen->x);
	split = ft_strsplit(line, ' ');
	while (split[i])
	{
		gen->map[gen->y][i] = malloc(sizeof(t_point));
		gen->map[gen->y][i]->x = i;
		gen->map[gen->y][i]->y = gen->y;
		gen->map[gen->y][i]->z = ft_atoi(split[i]);
		gen->map[gen->y][i]->o = 1;
		gen->map[gen->y][i]->old_z = gen->map[gen->y][i]->z;
		if (gen->map[gen->y][i]->z > gen->z)
			gen->z = gen->map[gen->y][i]->z;
		i++;
	}
	if (i != gen->x)
		ft_error_map(NULL);
	ft_freetab(split);
}

void		ft_save_map(int ac, char **av, t_gen *gen)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (ac != 2)
		ft_error_files(ac);
	if ((fd = open(av[1], O_RDONLY)) < 0 || !ft_isfile(av[1]) || ft_isdir(av[1]))
		ft_error_pass();
	gen->filename = ft_strdup(av[1]);
	ft_check_file(gen);
	gen->map = malloc(sizeof(t_point**) * gen->y);
	gen->y = 0;
	while (get_next_line(fd, &line))
	{
		ft_save_line(line, gen);
		free(line);
		gen->y++;
	}
	close(fd);
}
