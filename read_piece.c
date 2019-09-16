/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:40:49 by rzero             #+#    #+#             */
/*   Updated: 2019/07/28 11:40:51 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	create_piece(t_filler *f)
{
	int i;

	i = 0;
	f->p = (int**)malloc(sizeof(int*) * f->p_h);
	while (i < f->p_h)
	{
		f->p[i] = (int*)malloc(sizeof(int) * f->p_w);
		i++;
	}
}

void	read_piece(t_filler *f, int fd)
{
	char	*s;
	char	**res;
	int		i;
	int		j;

	get_next_line(fd, &s);
	res = ft_strsplit(s, ' ');
	f->p_h = ft_atoi(res[1]);
	f->p_w = ft_atoi(res[2]);
	create_piece(f);
	i = 0;
	while (i < f->p_h)
	{
		j = 0;
		get_next_line(fd, &s);
		while (j < f->p_w)
		{
			f->p[i][j] = (s[j] == '*') ? 1 : 0;
			j++;
		}
		i++;
		ft_strdel(&s);
	}
}
