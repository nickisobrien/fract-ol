/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:46:24 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/08 01:03:02 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init(t_world *w, char *board)
{
	if (!set_board_type(w, board))
		usage();
	w->mlx = mlx_init();
	w->window = mlx_new_window(w->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	w->cam.s = 0.02;
	w->cam.x = 0.0;
	w->cam.y = 0.0;
	w->frac.color = 0xffffff;//abs((int)random());
	w->frac.eb = COLORB;
	w->mouse.x = 0;
	w->mouse.y = 0;
	init_image(w);
	mlx_hook(w->window, 2, 0, key_pressed_hook, w);
	mlx_hook(w->window, 6, 0, mouse_moved_hook, w);
	mlx_hook(w->window, 4, 0, mouse_wheel_hook, w);
	key_menu();
	draw(w);
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
