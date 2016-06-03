/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:32 by lucas             #+#    #+#             */
/*   Updated: 2016/06/01 14:32:49 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* De bas en haut */

void	octan_1(t_gen *gen, t_point *p1, t_point *p2)
{
    int		e;
    int		dx;
    int		dy;

    e = p2->y - p1->y;
    dy = e * 2;
    dx = (p2->x - p1->x) * 2;
    while (p1->y <= p2->y)
    {
        ft_put_pixel(gen, p1->x, p1->y, p1->old_z, p2->old_z);
        p1->y++;
        if ((e = e - dx) <= 0)
        {
            p1->x++;
            e = e + dy;
        }
    }
}

void	octan_2(t_gen *gen, t_point *p1, t_point *p2)
{
	int		e;
    int		dx;
    int		dy;

	e = p2->x - p1->x;
	dx = e * 2;
	dy = (p2->y - p1->y) * 2;
	while (p1->x <= p2->x)
	{
		ft_put_pixel(gen, p1->x, p1->y, p1->old_z, p2->old_z);
		p1->x++;
		if ((e = e - dy) <= 0)
		{
			p1->y++;
			e = e + dx;
		}
	}
}

void	octan_3(t_gen *gen, t_point *p1, t_point *p2)
{
	int		e;
    int		dx;
    int		dy;

	e = p2->x - p1->x;
	dx = e * 2;
	dy = (p1->y - p2->y) * 2;
	while (p1->x <= p2->x)
	{
		ft_put_pixel(gen, p1->x, p1->y, p1->old_z, p2->old_z);
		p1->x++;
		if ((e = e - dy) <= 0)
		{
			p1->y--;
			e = e + dx;
		}
	}
}

void	octan_4(t_gen *gen, t_point *p1, t_point *p2)
{
	int		e;
    int		dx;
    int		dy;

	e = p1->y - p2->y;
	dy = e * 2;
	dx = (p2->x - p1->x) * 2;
	while (p1->y >= p2->y)
	{
		ft_put_pixel(gen, p1->x, p1->y, p1->old_z, p2->old_z);
		p1->y--;
		if ((e = e - dx) <= 0)
		{
			p1->x++;
			e = e + dy;
		}
	}
}
