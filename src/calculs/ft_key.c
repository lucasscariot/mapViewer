/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:44:59 by lscariot          #+#    #+#             */
/*   Updated: 2016/06/06 02:20:13 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_hook(int button, int x, int y, t_gen *gen)
{
	(void)x;
	(void)y;
	if (button == 5)
		ft_multiply(gen);
	if (button == 4)
		ft_divise(gen);
	return (0);
}

void	ft_up_down(t_gen *gen, int i)
{
	if (i)
		gen->origin->y+= MOVE;
	else
		gen->origin->y-= MOVE;
	ft_show_map(gen);
}

void	ft_right_left(t_gen *gen, int i)
{
	if (i)
		gen->origin->x+= MOVE;
	else
		gen->origin->x-= MOVE;
	ft_show_map(gen);
}

int		ft_key_hook(int keycode, t_gen *gen)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 69 || keycode == 24)
		ft_multiply(gen);
	else if (keycode == 27 || keycode == 78)
		ft_divise(gen);
	else if (keycode == 123)
		ft_right_left(gen, 0);
	else if (keycode == 124)
		ft_right_left(gen, 1);
	else if (keycode == 125)
		ft_up_down(gen, 1);
	else if (keycode == 126)
		ft_up_down(gen, 0);
	else if (keycode == 13)
		ft_rotate_x(gen);
	else if (keycode == 2)
		ft_rotate_y(gen);
	else if (keycode == 14)
		ft_rotate_z(gen);
	else if (keycode == 1)
		ft_rotate_xx(gen);
	else if (keycode == 0)
		ft_proj_ortho(gen);
	else
	{
		ft_putstr("Key | Keycode: ");
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	return (0);
}
