/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:35:41 by lucas             #+#    #+#             */
/*   Updated: 2016/05/28 19:49:25 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_window(t_gen *gen)
{
	gen->mlx = mlx_init();
	gen->win = mlx_new_window(gen->mlx, WIN_X, WIN_Y, gen->filename);
}
