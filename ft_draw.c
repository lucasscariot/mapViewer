/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 22:41:03 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/19 02:35:44 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
   void	ft_draw(void *mlx, void *win, int xb, int yxd, int yd)
   {
   int x;
   double dx;
   double dy;
   double m;
   double y;

   dx = xb - xd;
   dy = yb - yd;
   m = dy / dx;
   y = yb;
   x = xb;
   while (x <= xd)
   {
   mlx_pixel_put(mlx, win, x,  (int)y + 0.5, 0xFFFFFF);
   y += m;
   x++;
   }
   }
   */

void	ft_draw(void *mlx, void *win, int x_max, int y_max)
{
	int	i;
	int	j;
	int	b;

	j = 0;
	while (j <= WIN_SIZE)
	{
		i = 0;
		b = 0;	
		while (i <= WIN_SIZE)
		{
			b = 0;
			while (b <= WIN_SIZE)
			{
				mlx_pixel_put(mlx, win, j, i + b, 0xFFFFFF);
				mlx_pixel_put(mlx, win, j + b, i, 0xFFFFFF);
				b++;
			}
			i = i + 40;
		}
		j = j + 40;
	}
}
