/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:54:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 19:49:59 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		set_frac(t_world *w, float *ca, float *cb)
{
	if (w->frac.frac == 1)
	{
		*ca = (float)(-1.0 + ((1.0 + 1.0) /
			(WIDTH - 0.0)) * (w->mouse.x - 0.0));
		*cb = (float)(-1.0 + ((1.0 + 1.0) /
			(WIDTH - 0.0)) * (w->mouse.y - 0.0));
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

void		error(void)
{
	ft_printf("Error\n");
	exit(-1);
}

void		set_color(t_world *w, int color, int a, int b)
{
	float bright;

	if (color != MAX_ITER)
	{
		bright = (0.0 + ((1.0 - 0.0) / (MAX_ITER - 0.0)) * (color - 0.0));
		bright = (w->frac.eb + ((LASTCOLOR - w->frac.eb) /
			(1.0 - 0.0)) * (sqrt(bright) - 0.0));
	}
	else
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}
