/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:40:57 by lucas             #+#    #+#             */
/*   Updated: 2016/05/20 20:43:23 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_isdir(char *filename)
{
	struct stat	stat;

	lstat(filename, &stat);
	if (!stat.st_dev)
		return (0);
	if (S_ISDIR(stat.st_mode))
		return (1);
	return (0);
}

int		ft_isfile(char *filename)
{
	struct stat state;

	if (lstat(filename, &state) == -1)
		return (0);
	return (1);
}
