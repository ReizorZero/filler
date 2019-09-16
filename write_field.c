/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:16:32 by rzero             #+#    #+#             */
/*   Updated: 2019/07/28 12:16:34 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_weight(t_filler *f, int y, int x)
{
	int i;
	int j;

	i = 0;
	while (i < f->h)
	{
		j = 0;
		while (j < f->w)
		{
			if (f->dmap[i][j] != -1 && f->dmap[i][j] != -2)
				if (f->dmap[i][j] > manhattan(x, y, j, i))
					f->dmap[i][j] = manhattan(x, y, j, i);
			j++;
		}
		i++;
	}
}

void	create_field(t_filler *f, int fd)
{
	int		i;
	char	*s;
	char	**res;

	get_next_line(fd, &s);
	res = ft_strsplit(s, ' ');
	f->h = ft_atoi(res[1]);
	f->w = ft_atoi(res[2]);
	i = 0;
	f->dmap = (int**)malloc(sizeof(int*) * f->h);
	while (i < f->h)
	{
		f->dmap[i] = (int*)malloc(sizeof(int) * f->w);
		i++;
	}
}

void	set_distances(t_filler *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->h)
	{
		j = 0;
		while (j < f->w)
		{
			if (f->dmap[i][j] == f->et)
				count_weight(f, i, j);
			j++;
		}
		i++;
	}
}

void	write_field(t_filler *f, int fd)
{
	char	*n;
	int		i;
	int		j;

	create_field(f, fd);
	get_next_line(fd, &n);
	i = 0;
	while (i < f->h)
	{
		j = 0;
		get_next_line(fd, &n);
		while (j < f->w)
		{
			if (n[j + 4] == 'X' || n[j + 4] == 'x')
				f->dmap[i][j] = -2;
			else if (n[j + 4] == 'O' || n[j + 4] == 'o')
				f->dmap[i][j] = -1;
			else
				f->dmap[i][j] = 9999;
			j++;
		}
		i++;
	}
	set_distances(f);
}
