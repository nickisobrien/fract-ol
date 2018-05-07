/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:46:24 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 15:17:06 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

float		ft_fmap(float input, float input_start, float input_end, float output_start, float output_end)
{
	return (output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start));
}

void		set_frac(t_world *w, float *ca, float *cb)
{
	if (w->frac.frac == 1)
	{
		*ca = ft_fmap(w->mouse.x, 0, WIDTH, -1, 1);
		*cb = ft_fmap(w->mouse.y, 0, HEIGHT, -1, 1);
	}
} 

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
		        	break;
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
			// mlx_pixel_put(w->mlx, w->window, x, y, bright);
		}
	}
	mlx_put_image_to_window(w->mlx, w->window, w->image.image, 0, 0);
}

int			key_pressed_hook(int key, t_world *w)
{
	if (key == 123 || key == 0)
	{
		w->cam.left -= 0.03;
		w->cam.right -= 0.03;
	}
	else if (key == 124 || key == 2)
	{
		w->cam.left += 0.03;
		w->cam.right += 0.03;
	}
	else if (key == 125 || key == 1)
	{
		w->cam.bottom += 0.03;
		w->cam.top += 0.03;
	}
	else if (key == 126 || key == 13)
	{
		w->cam.bottom -= 0.03;
		w->cam.top -= 0.03;
	}
	else if (key == 12)
		w->cam.s *= 1.05; //need to do some adjusting on x and y to make it zoom to middle
	else if (key == 14)
		w->cam.s *= 0.95; //need to do some adjusting on x and y to make it zoom to middle
	else if (key == 8)
		w->frac.color = (int)rand();
	else if (key == 53)
		exit(0);
	else if (key == 6)
		w->frac.effect = 255;
	else if (key == 7)
		w->frac.effect = 0xffffff;
	else if (key == 18)
		w->frac.frac = 0;
	else if (key == 19)
		w->frac.frac = 1;
	clear_image(w);
	draw_mandelbrot(w);
	return (0);
}

int		mouse_moved_hook(int x, int y, t_world *w)
{
	if (w->frac.frac == 1)
	{
		if (x > 0 && x < WIDTH)
			w->mouse.x = x;
		if (y > 0 && y < HEIGHT)
			w->mouse.y = y;
		clear_image(w);
		draw_mandelbrot(w);
	}
	return (0);
}

int		main(void)
{
	t_world w;

	w.mlx = mlx_init();
	w.window = mlx_new_window(w.mlx, WIDTH, HEIGHT, WINDOW_NAME);
	w.cam.s = 3;
	w.cam.left = -1;
	w.cam.right = 1;
	w.cam.top = -1;
	w.cam.bottom = 1;
	w.frac.color = 0xffffff;
	w.frac.effect = 255;
	w.frac.frac = 0;
	w.mouse.x = 0;
	w.mouse.y = 0;
	init_image(&w);
	mlx_hook(w.window, 2, 0, key_pressed_hook, &w);
	mlx_hook(w.window, 6, 0, mouse_moved_hook, &w);
	clear_image(&w);
	draw_mandelbrot(&w);
	key_menu();



	
	mlx_loop(w.mlx);
	return (0);
}
