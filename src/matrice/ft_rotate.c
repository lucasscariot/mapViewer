/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:57:50 by lucas             #+#    #+#             */
/*   Updated: 2016/06/05 21:42:24 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_app_matrice(t_gen *gen)
{
	int		x;
	int		y;
	double	t[3];
	t_mat	*m;

	m = &gen->mat;
	y = 0;
	while (y < gen->y)
	{
		x = 0;
		while (x < gen->x)
		{
			t[0] = gen->map[y][x]->x;
			t[1] = gen->map[y][x]->y;
			t[2] = gen->map[y][x]->z;
			gen->map[y][x]->x = ((t[0] * m->a) + (t[1] *
				m->b) + (t[2] * m->c));
			gen->map[y][x]->y = ((t[0] * m->d) + (t[1] *
				m->e) + (t[2] * m->f));
			gen->map[y][x]->z = ((t[0] * m->g) + (t[1] *
				m->h) + (t[2] * m->i));
			x++;
		}
		y++;
	}
}

void 	ft_rotate_xx(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = 1;
	gen->mat.e = cos(-THETA);
	gen->mat.f = -sin(-THETA);
	gen->mat.h = sin(-THETA);
	gen->mat.i = cos(-THETA);
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void 	ft_rotate_x(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = 1;
	gen->mat.e = cos(THETA);
	gen->mat.f = -sin(THETA);
	gen->mat.h = sin(THETA);
	gen->mat.i = cos(THETA);
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void	ft_rotate_y(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = cos(THETA);
	gen->mat.c = sin(THETA);
	gen->mat.e = 1;
	gen->mat.g = -sin(THETA);
	gen->mat.i = cos(THETA);
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void	ft_rotate_yy(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = cos(-THETA);
	gen->mat.c = sin(-THETA);
	gen->mat.e = 1;
	gen->mat.g = -sin(-THETA);
	gen->mat.i = cos(-THETA);
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void 	ft_rotate_z(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = cos(THETA);
	gen->mat.b = sin(THETA);
	gen->mat.f = 1;
	gen->mat.i = -sin(THETA);
	gen->mat.k = cos(THETA);
	gen->mat.p = 1;
	ft_app_matrice(gen);
	ft_show_map(gen);
}
