/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas    <lucas   @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:57:50 by lucas             #+#    #+#             */
/*   Updated: 2016/06/06 01:41:05 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show(t_gen *gen)
{
	ft_putstr("\033c");
	ft_putcolor("Welcome to FDF\n\n", BLUE);
	ft_putcolor("Opening : ", GREEN);
	ft_putendl(gen->filename);
	ft_putcolor("Map size : ", GREEN);
	ft_putnbr(gen->x);
	ft_putchar('x');
	ft_putnbr(gen->y);
	ft_putchar('[');
	ft_putnbr(gen->z);
	ft_putstr("]\n");
}
