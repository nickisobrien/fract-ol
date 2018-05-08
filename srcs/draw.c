/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:51:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 20:34:40 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		draw_mandelbrot(t_world *w)
{
	float	maxiter;
	int		x;
	int		y;
	float	a;
	float	b;
	float	aa;
	float	bb;
	float	ca;
	float	cb;
	int		n;
	float	bright;
	float	twoab;

	maxiter = 100;
	x = -1;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			a = ft_fmap(x, 0, WIDTH, w->cam.left * w->cam.s, w->cam.right * w->cam.s);
			b = ft_fmap(y, 0, HEIGHT, w->cam.top * w->cam.s, w->cam.bottom * w->cam.s);
			ca = a;
			cb = b;
			set_frac(w, &ca, &cb);
			n = 0;
			while (n < maxiter)
			{
				aa = a * a;
		        bb = b * b;
		        if (aa + bb > 6.0)//can be dynamic, it's how many it'll draw, could do > x && < y to go deeper?
		        	break ;
		        twoab = 2.0 * a * b;
		    	a = aa - bb + ca;
		    	b = twoab + cb;
		        n++;
			}
			bright = ft_fmap(n, 0, maxiter, 0, 1);//setting color based on how many iterations there were
			bright = ft_fmap(sqrt(bright), 0, 1, 0, w->frac.effect);
			if (n == maxiter)
				bright = w->frac.color;
			img_pixel_put(&w->image, x, y, bright);
		}
	}
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}

void		draw_burningship(t_world *w)
{
	int		a;
	int		b;
	float	x;
	float	y;
	float	zx;
	float	zy;
	float	zxzx;
	float	zyzy;
	int		iter;
	int		maxiter;
	float	bright;

	maxiter = 1000;
	a = -1;
	while (++a < WIDTH)
	{
		b = -1;
		while (++b < HEIGHT)
		{
			x = ft_fmap(a, 0, WIDTH, w->cam.left * w->cam.s, w->cam.right * w->cam.s);
			y = ft_fmap(b, 0, HEIGHT, w->cam.top * w->cam.s, w->cam.bottom * w->cam.s);
			zx = x;
			zy = y;
			iter = 0;
			while (iter < maxiter)
			{
				zxzx = zx * zx;
				zyzy = zy * zy;
				if (zxzx + zyzy > 6.0)
					break ;
				zy = fabsf(2 * zx * zy) + y;
				zx = fabsf(zxzx - zyzy + x);
				iter++;
			}
			bright = ft_fmap(iter, 0, maxiter, 0, 1);//setting color based on how many iterations there were
			bright = ft_fmap(sqrt(bright), 0, 1, 0, w->frac.effect);
			if (iter == maxiter)
				bright = w->frac.color;
			img_pixel_put(&w->image, a, b, bright);
		}
	}
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}
