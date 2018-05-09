/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:54:06 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/09 02:54:17 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		set_frac(t_world *w, long double *ca, long double *cb)
{
	if (w->frac.frac == 1)
	{
		*ca = -1.0 + 2.0 / WIDTH * w->mouse.x;
		*cb = -1.0 + 2.0 / HEIGHT * w->mouse.y;
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
		bright = ((1.0 / w->max_iter) * color);
		bright = (w->frac.eb + ((LASTCOLOR * (1000000.0 / w->frac.color)
			- w->frac.eb) / 1.0) * sqrt(bright));
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
