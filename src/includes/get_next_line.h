/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 08:31:33 by lscariot          #+#    #+#             */
/*   Updated: 2016/06/01 11:06:20 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2000

# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_gnl
{
	char	*buff;
	char	*rest;
	int		read;
	int		ret;
	int		i;
}				t_gnl;
int				get_next_line(int const fd, char **line);

#endif
