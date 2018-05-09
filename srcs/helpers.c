/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:54:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 21:18:32 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		set_frac(t_world *w, long double *ca, long double *cb)
{
	if (w->frac.frac == 1)
	{
		*ca = (long double)(-1.0 + ((1.0 + 1.0) /
			(WIDTH - 0.0)) * (w->mouse.x - 0.0));
		*cb = (long double)(-1.0 + ((1.0 + 1.0) /
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
	long double bright;

	if (color != w->max_iter)
	{
		bright = (0.0 + ((1.0 - 0.0) / (w->max_iter - 0.0)) * (color - 0.0));
		bright = (w->frac.eb + ((LASTCOLOR - w->frac.eb) /
			(1.0 - 0.0)) * (sqrt(bright) - 0.0));
	}
	else
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}

void		reset(t_world *w)
{
	w->cam.s = 0.02;
	w->cam.x = 0.0;
	w->cam.y = 0.0;
	w->frac.color = 0xffffff;
	w->frac.eb = COLORB;
	w->mouse.x = 0;
	w->mouse.y = 0;
	w->max_iter = STARTING_ITER;
	w->mouse.active = 1;
	draw(w);
}
