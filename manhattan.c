/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:37:26 by rzero             #+#    #+#             */
/*   Updated: 2019/07/28 11:37:29 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	mod(int i)
{
	return ((i >= 0) ? i : -i);
}

int			manhattan(int x1, int y1, int x2, int y2)
{
	return ((mod(x1 - x2)) + mod(y1 - y2));
}

int			is_position(t_filler *f)
{
	if (f->out_x == 999999 || f->out_y == 999999)
		return (0);
	return (1);
}

int			change_output(t_filler *f, int i, int j, int sum)
{
	f->out_x = j;
	f->out_y = i;
	return (sum);
}
