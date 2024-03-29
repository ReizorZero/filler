/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:24:00 by rzero             #+#    #+#             */
/*   Updated: 2019/03/07 17:24:09 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define YO return(1);
# define BYKA return(-1);
# define ZERO return(0);
# define BUFF_SIZE 2
# define CHECKMEM(x) if (!(x)) return (NULL);
# define SWAP(x, y, z) x = y; y = z; free(x);
# define N_INDEX (all_buf - buf)
# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			*buf;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
