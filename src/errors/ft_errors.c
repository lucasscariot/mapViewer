/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 09:45:45 by lucas             #+#    #+#             */
/*   Updated: 2016/05/18 13:40:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_err_base(void)
{
	ft_putstr("\e[91m");
	ft_putstr("Oops : ");
}

void	ft_err_end(void)
{
	ft_putstr("\e[0m\n");
	exit(1);
}

void	ft_error_files(int i)
{
	ft_err_base();
	if (i < 2)
		ft_putstr("Send me a file!");
	else if (i > 2)
		ft_putstr("Too many files for me!");
	ft_err_end();
}

void	ft_error_pass(void)
{
	ft_err_base();
	ft_putcolor("Invalid file!", RED);
	ft_err_end();
}

void	ft_error_map(t_gen *gen)
{
	(void)gen;
	ft_err_base();
	ft_putcolor("Invalid map", RED);
	ft_err_end();
}
