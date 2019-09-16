/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:19:01 by rzero             #+#    #+#             */
/*   Updated: 2019/07/28 11:19:03 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_output(t_filler *f)
{
	ft_putnbr(f->out_y);
	ft_putchar(' ');
	ft_putnbr(f->out_x);
	ft_putchar('\n');
}

int		place_found(int cover)
{
	return ((cover == 1) ? 1 : 0);
}

int		check_place(t_filler *f, int i, int j)
{
	int x;
	int y;
	int cover;

	cover = 0;
	y = 0;
	while (y < f->p_h)
	{
		if (i + y >= f->h)
			return (0);
		x = 0;
		while (x < f->p_w)
		{
			if (j + x >= f->w)
				return (0);
			if (f->p[y][x] == 1 && (f->dmap[i + y][j + x] == f->et))
				return (0);
			if (f->p[y][x] == 1 && (f->dmap[i + y][j + x] == f->t))
				cover++;
			x++;
		}
		y++;
	}
	return (place_found(cover));
}

int		find_sum(t_filler *f, int i, int j)
{
	int x;
	int y;
	int sum;

	sum = 0;
	y = 0;
	while (y < f->p_h)
	{
		x = 0;
		while (x < f->p_w)
		{
			if (f->p[y][x] == 1 && f->dmap[i + y][j + x] != f->t)
				sum += f->dmap[i + y][j + x];
			x++;
		}
		y++;
	}
	return (sum);
}

int		found_position(t_filler *f)
{
	int i;
	int j;
	int sum;
	int prev_sum;

	f->out_x = 999999;
	f->out_y = 999999;
	prev_sum = 999999;
	i = 0;
	while (i < f->h)
	{
		j = 0;
		while (j < f->w)
		{
			if (check_place(f, i, j) == 1)
			{
				sum = find_sum(f, i, j);
				if (sum < prev_sum)
					prev_sum = change_output(f, i, j, sum);
			}
			j++;
		}
		i++;
	}
	return (is_position(f));
}
