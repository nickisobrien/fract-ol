/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:02:42 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 21:30:00 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	usage(void)
{
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("Fractals:\n'1': Mandelbrot\n'2': Julia\n'3': Burningship\n");
	exit(-1);
}

void	key_menu(void)
{
	ft_printf("Move: 'W', 'A', 'S', 'D'\n");
	ft_printf("Zoom: (in)'E', (out)'Q', MOUSE WHEEL\n");
	ft_printf("Color: 'C'\n");
	ft_printf("Mode: (normal)'Z', (psychedelic)'X'\n");
	ft_printf("Fractal:\n(mandelbrot)'1'\n(julia)'2'\n");
}
