/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:51:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 01:00:37 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			draw_mandelbrot(t_world *w, float x, float y)
{
	float	zx;
	float	zy;
	float	xx;
	float	yy;
	int		iter;

	zx = x;
	zy = y;
	set_frac(w, &zx, &zy);
	iter = -1;
	while (++iter < MAX_ITER)
	{
		xx = x * x;
		yy = y * y;
		if (xx + yy > 6.0)
			break ;
		y = (2.0 * x * y) + zy;
		x = xx - yy + zx;
	}
	return (iter);
}

int			draw_burningship(float x, float y)
{
	float	zx;
	float	zy;
	float	zxzx;
	float	zyzy;
	int		iter;

	zx = x;
	zy = y;
	iter = -1;
	while (++iter < MAX_ITER)
	{
		zxzx = zx * zx;
		zyzy = zy * zy;
		if (zxzx + zyzy > 6.0)
			break ;
		zy = fabsf(2 * zx * zy) + y;
		zx = fabsf(zxzx - zyzy + x);
	}
	return (iter);
}

void		set_color(t_world *w, int color, int a, int b)
{
	float bright;

	bright = ft_fmap(color, 0, MAX_ITER, 0, 1);
	bright = ft_fmap(sqrt(bright), 0, 1, w->frac.eb, LASTCOLOR);
	if (color == MAX_ITER)
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}

void		draw(t_world *w)
{
	int		a;
	int		b;
	int		color;
	double	real;
	double	imagstart;
	double	imag;

	clear_image(&w->image);
	real = 0 * w->cam.s - WIDTH / 2.0 * w->cam.s + w->cam.x;
	imagstart = 0 * w->cam.s - HEIGHT / 2.0 * w->cam.s + w->cam.y;
	a = -1;
	while (++a < WIDTH)
	{
		imag = imagstart;
		b = -1;
		while (++b < HEIGHT)
		{
			if (w->frac.frac == 0 || w->frac.frac == 1)
				color = draw_mandelbrot(w, real, imag);
			else if (w->frac.frac == 2)
				color = draw_burningship(real, imag);
			set_color(w, color, a, b);
			imag += w->cam.s;
		}
		real += w->cam.s;
	}
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}
