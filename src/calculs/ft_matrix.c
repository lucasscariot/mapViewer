/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:32 by lucas             #+#    #+#             */
/*   Updated: 2016/05/31 14:23:26 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		**ft_matrix_x(void)
{
	double		**matrix;

	matrix = malloc(sizeof(int) * 3);
	matrix[0] = malloc(sizeof(int) * 3);
	matrix[1] = malloc(sizeof(int) * 3);
	matrix[2] = malloc(sizeof(int) * 3);
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[2][1] = cos(THETA);
	matrix[3][2] = -sin(THETA);
	matrix[2][0] = 0;
	matrix[2][1] = sin(THETA);
	matrix[2][2] = cos(THETA);
	return (matrix);
}
