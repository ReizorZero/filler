/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:31:30 by rzero             #+#    #+#             */
/*   Updated: 2019/07/29 11:21:14 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>

typedef struct		s_visual
{
	char	t;
	char	et;
	int		f_x;
	int		f_y;
	int		o_score;
	int		x_score;
}					t_visual;

void				set_field_size(t_visual *v, char *s);
void				output_field(t_visual *v, char *s);

#endif
