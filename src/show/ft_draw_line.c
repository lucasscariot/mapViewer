/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas    <lucas   @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:32 by lucas             #+#    #+#             */
/*   Updated: 2016/06/06 01:23:36 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_put_pixel(t_gen *gen, int x, int y, int z, int z2)
{
    int     pos;
	int		col[3];

    if (x >= WIN_X || y >= WIN_Y || x < 0 || y < 0)
        return ;
	ft_choose_color(&col[0], &col[1], &col[2], z, z2);
    pos = x * 4 + y * gen->img->size_line;
	gen->img->data[pos] = col[0];
	gen->img->data[pos + 1] = col[1];
	gen->img->data[pos + 2] = col[2];
}

void	ft_swap_point(t_point **p1, t_point **p2)
{
	t_point *tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void 	ft_init_point(t_gen *gen, t_point *p)
{
	p->x = (p->x - gen->origin->x) * gen->zoom + WIN_X / 2;
	p->y = (p->y - gen->origin->y) * gen->zoom + WIN_Y / 2;
}

void    ft_draw_line(t_gen *gen, t_point *p1, t_point *p2)
{
    int     dx;
    int     dy;
    double     save[4];

	save[0] = p1->x;
    save[1] = p1->y;
	save[2] = p2->x;
	save[3] = p2->y;
    if ((p2->x - p1->x) < 0)
		ft_swap_point(&p1, &p2);
	ft_init_point(gen, p1);
	ft_init_point(gen, p2);
    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    if (dx <= dy && dy >= 0 && dx >= 0)
		octan_1(gen, p1, p2);
    else if (dx >= dy && dy >= 0 && dx >= 0)
		octan_2(gen, p1, p2);
    else if (dx >= -dy && dy <= 0 && dx >= 0)
		octan_3(gen, p1, p2);
	else if (dx <= -dy && dy <= 0 && dx >= 0)
        octan_4(gen, p1, p2);
	if ((p1->x - p2->x) < 0)
		ft_swap_point(&p1, &p2);
    p1->x = save[0];
    p1->y = save[1];
	p2->x = save[2];
	p2->y = save[3];
}
