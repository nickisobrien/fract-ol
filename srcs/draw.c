/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:51:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 21:07:58 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		draw_mandelbrot(t_world *w, int a, int b)
{
	float	x;
	float	y;
	float	zx;
	float	zy;
	float	xx;
	float	yy;
	int		iter;
	int		maxiter;
	float	bright;
	float	twoab;

	maxiter = 100;
	x = ft_fmap(a, 0, WIDTH, w->cam.left * w->cam.s, w->cam.right * w->cam.s);
	y = ft_fmap(b, 0, HEIGHT, w->cam.top * w->cam.s, w->cam.bottom * w->cam.s);
	zx = x;
	zy = y;
	set_frac(w, &zx, &zy);
	iter = -1;
	while (++iter < maxiter)
	{
		xx = x * x;
		yy = y * y;
		if (xx + yy > 6.0)
			break ;
		twoab = 2.0 * x * y;
		x = xx - yy + zx;
		y = twoab + zy;
	}
	bright = ft_fmap(iter, 0, maxiter, 0, 1);//setting color based on how many iterations there were
	bright = ft_fmap(sqrt(bright), 0, 1, 0, w->frac.effect);
	if (iter == maxiter)
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}

void		draw_burningship(t_world *w, int a, int b)
{
	float	x;
	float	y;
	float	zx;
	float	zy;
	float	zxzx;
	float	zyzy;
	int		iter;
	int		maxiter;
	float	bright;

	maxiter = 100;
	x = ft_fmap(a, 0, WIDTH, w->cam.left * w->cam.s, w->cam.right * w->cam.s);
	y = ft_fmap(b, 0, HEIGHT, w->cam.top * w->cam.s, w->cam.bottom * w->cam.s);
	zx = x;
	zy = y;
	set_frac(w, &zx, &zy);
	iter = -1;
	while (++iter < maxiter)
	{
		zxzx = zx * zx;
		zyzy = zy * zy;
		if (zxzx + zyzy > 6.0)
			break ;
		zy = fabsf(2 * zx * zy) + y;
		zx = fabsf(zxzx - zyzy + x);
	}
	bright = ft_fmap(iter, 0, maxiter, 0, 1);//setting color based on how many iterations there were
	bright = ft_fmap(sqrt(bright), 0, 1, 0, w->frac.effect);
	if (iter == maxiter)
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}

void		draw(t_world *w)
{
	int		a;
	int		b;

	a = -1;
	while (++a < WIDTH)
	{
		b = -1;
		while (++b < HEIGHT)
		{
			if (w->frac.frac == 0 || w->frac.frac == 1)
				draw_mandelbrot(w, a, b);
			else if (w->frac.frac == 2)
				draw_burningship(w, a, b);
		}
	}
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}
