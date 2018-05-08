/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:51:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 22:13:57 by nobrien          ###   ########.fr       */
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
	bright = ft_fmap(sqrt(bright), 0, 1, 0, w->frac.eb);
	if (color == MAX_ITER)
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}

void		draw(t_world *w)
{
	int		a;
	int		b;
	int		color;

	clear_image(w);
	a = -1;
	while (++a < WIDTH)
	{
		b = -1;
		while (++b < HEIGHT)
		{
			if (w->frac.frac == 0 || w->frac.frac == 1)
				color = draw_mandelbrot(w, ft_fmap(a, 0, WIDTH, w->cam.left * w->cam.s, w->cam.right * w->cam.s), ft_fmap(b, 0, HEIGHT, w->cam.top * w->cam.s, w->cam.bottom * w->cam.s));
			else if (w->frac.frac == 2)
				color = draw_burningship(ft_fmap(a, 0, WIDTH, w->cam.left * w->cam.s, w->cam.right * w->cam.s), ft_fmap(b, 0, HEIGHT, w->cam.top * w->cam.s, w->cam.bottom * w->cam.s));
			set_color(w, color, a, b);
		}
	}
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}
