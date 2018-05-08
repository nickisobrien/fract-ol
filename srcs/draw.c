/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:51:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 06:35:04 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int				draw_mandelbrot(t_world *w, float x, float y)
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
			return (iter);
		y = (2.0 * x * y) + zy;
		x = xx - yy + zx;
	}
	return (iter);
}

int				draw_burningship(float x, float y)
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
			return (iter);
		zy = fabsf(2 * zx * zy) + y;
		zx = fabsf(zxzx - zyzy + x);
	}
	return (iter);
}

static void		draw_from(t_world *w, int a, int end)
{
	int			b;
	int			color;
	float		real;
	float		imagstart;
	float		imag;

	real = 0 * w->cam.s - WIDTH / 2.0 * w->cam.s + w->cam.x + (w->cam.s * a);
	imagstart = 0 * w->cam.s - HEIGHT / 2.0 * w->cam.s + w->cam.y;
	a -= 1;
	while (++a < end && a < WIDTH)
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
}

static void		*drawt(void *obj)
{
	int			i;
	t_world		*w;

	i = ((t_data *)obj)->job;
	w = (t_world*)((t_data *)obj)->w;
	if (i >= THREADS)
		return (NULL);
	if (i == 0)
		draw_from(w, 0, (WIDTH / THREADS) * (i + 1));
	else
		draw_from(w, (WIDTH / THREADS) * i, (WIDTH / THREADS) * (i + 1));
	return (NULL);
}

void			draw(t_world *w)
{
	pthread_t	threads[THREADS];
	int			i;
	t_data		data[THREADS];

	i = -1;
	w->job = 0;
	clear_image(&w->image);
	while (++i < THREADS)
	{
		data[i].job = i;
		data[i].w = w;
		if (pthread_create(&threads[i], NULL, &drawt, &data[i]))
			error();
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(threads[i], NULL))
			error();
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}
