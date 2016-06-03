/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:55 by lscariot          #+#    #+#             */
/*   Updated: 2016/06/02 12:50:45 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_mat(t_gen *gen)
{
	gen->mat.a = 0;
	gen->mat.b = 0;
	gen->mat.c = 0;
	gen->mat.d = 0;
	gen->mat.e = 0;
	gen->mat.f = 0;
	gen->mat.g = 0;
	gen->mat.h = 0;
	gen->mat.i = 0;
}
