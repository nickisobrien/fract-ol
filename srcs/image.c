/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:28:59 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 21:31:27 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_image(t_world *w)
{
	w->image.image = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->image.ptr = mlx_get_data_addr(w->image.image,
		&w->image.bpp, &w->image.size_line, &w->image.endian);
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(img->ptr + (int)((y * WIDTH + x) * (img->bpp / 8))) = color;
}

void	clear_image(t_world *w)
{
	ft_bzero(w->image.ptr, WIDTH * HEIGHT * (w->image.bpp / 8));
}
