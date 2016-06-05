/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:32 by lucas             #+#    #+#             */
/*   Updated: 2016/06/05 14:58:00 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	ft_ini_origin(t_gen *gen)
{
	gen->origin = malloc(sizeof(t_point));
	gen->origin->x = gen->x / 2;
	gen->origin->y = gen->y / 2;
	gen->origin->z = gen->z / 2;
	gen->zoom = 8;
}

int		main(int ac, char **av)
{
	t_gen	gen;

	(void)av;
	(void)ac;
	(void)gen;
	ft_save_map(ac, av, &gen);
	ft_ini_origin(&gen);
	ft_create_window(&gen);
	mlx_key_hook(gen.win, ft_key_hook, &gen);
	mlx_mouse_hook(gen.win, ft_mouse_hook, &gen);
	ft_show(&gen);
	ft_show_map(&gen);
	mlx_loop(gen.mlx);
	return (0);
}
