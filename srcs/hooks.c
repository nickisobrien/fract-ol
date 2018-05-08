/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:49:28 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 22:07:37 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_pressed_hook(int key, t_world *w)
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
		w->cam.s *= ZOOM_SPEED; //need to do some adjusting on x and y to make it zoom to middle
	else if (key == 14)
		w->cam.s /= ZOOM_SPEED; //need to do some adjusting on x and y to make it zoom to middle
	else if (key == 8)
		w->frac.color = (int)rand();
	else if (key == 53)
		exit(0);
	else if (key == 6)
		w->frac.effect_b = 255;
	else if (key == 7)
		w->frac.effect_b = 0xffffff;
	else if (key == 18)
		w->frac.frac = 0;
	else if (key == 19)
		w->frac.frac = 1;
	else if (key == 20)
		w->frac.frac = 2;
	draw(w);
	return (0);
}

int		mouse_wheel_hook(int button, int x, int y, t_world *w)
{
	(void)w;
	(void)x;
	(void)y;
	if (button == 4)
		w->cam.s *= ZOOM_SPEED;
	if (button == 5)
		w->cam.s /= ZOOM_SPEED;
	draw(w);
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
		draw(w);
	}
	return (0);
}
