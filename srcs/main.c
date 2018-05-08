/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:46:24 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/07 22:07:42 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init(t_world *w, char *board)
{
	if (!set_board_type(w, board))
		usage();
	w->mlx = mlx_init();
	w->window = mlx_new_window(w->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	w->cam.s = 5;
	w->cam.left = -1;
	w->cam.right = 1;
	w->cam.top = -1;
	w->cam.bottom = 1;
	w->frac.color = 0xffffff;
	w->frac.effect_b = 255;
	w->mouse.x = 0;
	w->mouse.y = 0;
	init_image(w);
	mlx_hook(w->window, 2, 0, key_pressed_hook, w);
	mlx_hook(w->window, 6, 0, mouse_moved_hook, w);
	mlx_hook(w->window, 4, 0, mouse_wheel_hook, w);
	draw(w);
	key_menu();
}

int		main(int argc, char **argv)
{
	t_world w;

	if (argc != 2)
		usage();
	init(&w, argv[1]);
	mlx_loop(w.mlx);
	return (0);
}
