/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:36:49 by rzero             #+#    #+#             */
/*   Updated: 2019/07/29 10:36:52 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	define_players(t_visual *v, char *s)
{
	v->t = (ft_strstr(s, "rzero")) ? 'O' : 'X';
	v->et = (v->t == 'O') ? 'X' : 'O';
}

void	set_field_size(t_visual *v, char *s)
{
	char	**res;

	res = ft_strsplit(s, ' ');
	v->f_y = ft_atoi(res[1]);
	v->f_x = ft_atoi(res[2]);
}

void	set_winner(t_visual *v, char *s)
{
	char	*n;
	char	**res;
	char	win;
	int		score;

	res = ft_strsplit(s, ' ');
	v->o_score = ft_atoi(res[3]);
	get_next_line(0, &n);
	res = ft_strsplit(n, ' ');
	v->x_score = ft_atoi(res[3]);
	ft_putstr_fd("\x1b[1;44mWINNER:\x1b[0m", 1);
	win = (v->x_score > v->o_score) ? 'X' : 'O';
	ft_putchar_fd(win, 1);
	score = (win == 'X') ? v->x_score : v->o_score;
	ft_putstr_fd("\x1b[1;46m\t\tSCORE:\x1b[0m", 1);
	ft_putnbr_fd(score, 1);
	ft_putstr_fd("\n\n", 1);
}

int		main(void)
{
	char		*s;
	int			i;
	t_visual	*v;

	v = (t_visual*)malloc(sizeof(t_visual));
	i = 0;
	while (get_next_line(0, &s) > 0)
	{
		while (i < 5)
		{
			get_next_line(0, &s);
			i++;
		}
		if (ft_strstr(s, "p1") != NULL)
			define_players(v, s);
		else if (ft_strstr(s, "Plateau") != NULL)
			output_field(v, s);
		else if (ft_strstr(s, "fin") != NULL)
			set_winner(v, s);
	}
	return (0);
}
