/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:54:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 01:35:48 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

float		ft_fmap(float input, float input_start,
	float input_end, float output_start, float output_end)
{
	return (output_start + ((output_end - output_start) /
		(input_end - input_start)) * (input - input_start));
}

void		set_frac(t_world *w, float *ca, float *cb)
{
	if (w->frac.frac == 1)
	{
		*ca = ft_fmap(w->mouse.x, 0, WIDTH, -1, 1);
		*cb = ft_fmap(w->mouse.y, 0, HEIGHT, -1, 1);
	}
}

int			set_board_type(t_world *w, char *board)
{
	if (!ft_strcmp(board, "1"))
		w->frac.frac = 0;
	else if (!ft_strcmp(board, "2"))
		w->frac.frac = 1;
	else if (!ft_strcmp(board, "3"))
		w->frac.frac = 2;
	else
		return (0);
	return (1);
}
