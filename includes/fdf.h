/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:03:02 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/18 23:45:59 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_SIZE 1000
# define PI 3.14159265359
# define BUFF_SIZE 4000

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct	s_point
{
	int	x;
	int y;
	int z;
}				t_point;

typedef struct	s_map
{
	int	x_max;
	int y_max;
}				t_map;

int				ft_mouse_hook(int button, int x, int y, t_env *e);
int				ft_key_hook(int keycode, t_env *e);
int				ft_expose_hook(t_env *e);
void			ft_error(int i);
t_point			*ft_read_map(char *file, t_map *map);
t_point			*ft_save_map(char ***str, int x_max, int y_max);
void			ft_draw(void *mlx, void *win, int x_max, int y_max);

#endif
