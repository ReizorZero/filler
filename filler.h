/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:15:06 by rzero             #+#    #+#             */
/*   Updated: 2019/07/28 11:15:12 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "libft/get_next_line.h"

# define FD 0

typedef struct	s_filler
{
	int	t;
	int	et;
	int	**dmap;
	int	w;
	int	h;
	int	**p;
	int	p_w;
	int	p_h;
	int	out_x;
	int	out_y;
}				t_filler;

void			define_player(t_filler *f, int fd);
void			write_field(t_filler *f, int fd);
void			read_piece(t_filler *f, int fd);
int				found_position(t_filler *f);
void			do_output(t_filler *f);

int				manhattan(int x1, int y1, int x2, int y2);
int				is_position(t_filler *f);
int				change_output(t_filler *f, int i, int j, int sum);

#endif
