/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:26:30 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/12 10:07:51 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	ft_putstr("Key | Keycode: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
