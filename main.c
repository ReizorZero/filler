/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:36:31 by rzero             #+#    #+#             */
/*   Updated: 2019/07/28 11:36:36 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler *f;

	f = (t_filler*)malloc(sizeof(t_filler));
	define_player(f, FD);
	while (2)
	{
		write_field(f, FD);
		read_piece(f, FD);
		if (found_position(f))
			do_output(f);
		else
			return (0);
	}
	return (0);
}
