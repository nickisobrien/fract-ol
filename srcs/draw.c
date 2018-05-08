/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:51:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 03:16:33 by nobrien          ###   ########.fr       */
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
			return (iter);
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
			return (iter);
		zy = fabsf(2 * zx * zy) + y;
		zx = fabsf(zxzx - zyzy + x);
	}
	return (iter);
}

void		set_color(t_world *w, int color, int a, int b)
{
	float bright;

	bright = ft_fmap(color, 0, MAX_ITER, 0, 1);//heavy?
	bright = ft_fmap(sqrt(bright), 0, 1, w->frac.eb, LASTCOLOR);//heavy?
	if (color == MAX_ITER)
		bright = w->frac.color;
	img_pixel_put(&w->image, a, b, bright);
}

void		*draw_thread(void *obj)
{
	int color;
	int b;
	t_data data;

	data = *(t_data *)obj;
	b = -1;
	while (++b < HEIGHT)
	{
		if (data.w->frac.frac == 0 || data.w->frac.frac == 1)
			color = draw_mandelbrot(data.w, data.real, data.imag);
		else if (data.w->frac.frac == 2)
			color = draw_burningship(data.real, data.imag);
		set_color(data.w, color, data.a, b);
		data.imag += data.w->cam.s;
	}
	return (NULL);
}

void		draw(t_world *w)
{
	int			a;
	float		real;
	float		imagstart;
	pthread_t	threads[WIDTH];
	t_data		data[WIDTH];

	clear_image(&w->image);
	real = 0 * w->cam.s - WIDTH / 2.0 * w->cam.s + w->cam.x;
	imagstart = 0 * w->cam.s - HEIGHT / 2.0 * w->cam.s + w->cam.y;
	a = -1;
	while (++a < WIDTH)
	{
		data[a].a = a;
		data[a].real = real;
		data[a].imag = imagstart;
		data[a].w = w;
		if (pthread_create(&threads[a], NULL, &draw_thread, &data[a]))
		{
			ft_printf("Threading error\n");
			exit (-1);
		}
		real += w->cam.s;
	}
	a = -1;
	while (++a < WIDTH)
		pthread_join(threads[a], NULL);
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}
