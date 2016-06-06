/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas    <lucas   @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:57:50 by lucas             #+#    #+#             */
/*   Updated: 2016/06/06 02:20:31 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_app_matrice(t_gen *gen)
{
	int		x;
	int		y;
	double	t[4];
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
			t[3] = gen->map[y][x]->o;
			gen->map[y][x]->x = ((t[0] * m->a) + (t[1] * m->b) + (t[2] * m->c) + (t[3] * m->d));
			gen->map[y][x]->y = ((t[0] * m->e) + (t[1] * m->f) + (t[2] * m->g) + (t[3] * m->h));
			gen->map[y][x]->z = ((t[0] * m->i) + (t[1] * m->j) + (t[2] * m->k) + (t[3] * m->l));
			gen->map[y][x]->o = ((t[0] * m->m) + (t[1] * m->n) + (t[2] * m->o) + (t[3] * m->p));
			x++;
		}
		y++;
	}
}

void	ft_proj_ortho(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = 1;
	gen->mat.c = 1;
	gen->mat.d = 2;
	gen->mat.f = 1;
	gen->mat.g = -1;
	gen->mat.h = 1;
	gen->mat.i = 1;
	gen->mat.k = 1;
	gen->mat.l = 1;
	gen->mat.n = 1;
	gen->mat.o = 1;
	gen->mat.p = 1;
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void 	ft_rotate_x(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = 1;
	gen->mat.f = cos(THETA);
	gen->mat.g = -sin(THETA);
	gen->mat.j = sin(THETA);
	gen->mat.k = cos(THETA);
	gen->mat.p = 1;
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void 	ft_rotate_xx(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = 1;
	gen->mat.f = cos(-THETA);
	gen->mat.g = -sin(-THETA);
	gen->mat.j = sin(-THETA);
	gen->mat.k = cos(-THETA);
	gen->mat.p = 1;
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void	ft_rotate_y(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = cos(THETA);
	gen->mat.c = sin(THETA);
	gen->mat.f = 1;
	gen->mat.i = -sin(THETA);
	gen->mat.k = cos(THETA);
	gen->mat.p = 1;
	ft_app_matrice(gen);
	ft_show_map(gen);
}

void	ft_rotate_yy(t_gen *gen)
{
	ft_init_mat(gen);
	gen->mat.a = cos(-THETA);
	gen->mat.c = sin(-THETA);
	gen->mat.f = 1;
	gen->mat.i = -sin(-THETA);
	gen->mat.k = cos(-THETA);
	gen->mat.p = 1;
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
