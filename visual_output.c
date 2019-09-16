/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:37:13 by rzero             #+#    #+#             */
/*   Updated: 2019/07/29 10:37:22 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	do_output(char s, t_visual *v)
{
	if (s == v->t)
		ft_putstr_fd("\x1b[1;41m \x1b[0m", 1);
	else if (s == ft_tolower(v->t))
		ft_putstr_fd("\x1b[1;41mx\x1b[0m", 1);
	else if (s == v->et)
		ft_putstr_fd("\x1b[1;42m \x1b[0m", 1);
	else if (s == ft_tolower(v->et))
		ft_putstr_fd("\x1b[1;42mo\x1b[0m", 1);
	else if (s == '.')
		ft_putstr_fd("\x1b[1;47m \x1b[0m", 1);
}

void	output_field(t_visual *v, char *s)
{
	int i;
	int j;

	set_field_size(v, s);
	get_next_line(0, &s);
	i = 0;
	while (i < v->f_y)
	{
		j = 0;
		get_next_line(0, &s);
		while (j < v->f_x)
		{
			do_output(s[j], v);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}
