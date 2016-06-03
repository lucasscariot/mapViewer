/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:55 by lucas             #+#    #+#             */
/*   Updated: 2016/06/02 12:38:15 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_divise(t_gen *gen)
{
	if (gen->zoom > 1)
		gen->zoom--;
	ft_show_map(gen);
}

void	ft_multiply(t_gen *gen)
{
	gen->zoom++;
	ft_show_map(gen);
}
