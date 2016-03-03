/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:47:21 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/18 23:46:01 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_env	e;
	t_point	*point;
	t_map	map;

	e.mlx = mlx_init();
	if (ac != 2)
		ft_error(1);
	system("clear");
	ft_putstr("FDF\n\nOpening file : ");
	ft_putendl(av[1]);
	ft_putchar('\n');
	e.win = mlx_new_window(e.mlx, WIN_SIZE + 1, WIN_SIZE + 1, "lscariot is wonderfull");
	point = ft_read_map(av[1], &map);
	ft_draw(e.mlx, e.win, map.x_max, map.y_max);
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_mouse_hook(e.win, ft_mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
