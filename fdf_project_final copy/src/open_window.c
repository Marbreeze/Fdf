/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:20:21 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 14:51:14 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_w(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		esc(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	open_window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1524, 1524, "FDF");
	print_figure(fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_w, (void *)0);
	mlx_hook(fdf->win_ptr, 2, 0, esc, (void *)0);
	mlx_loop(fdf->mlx_ptr);
}
