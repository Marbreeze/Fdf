/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:20:04 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 13:23:58 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_fdf		fdf;
	t_fdf_list	*list;

	list = NULL;
	ft_bzero(&fdf, sizeof(t_fdf));
	make_fdf_values_to_zero(&fdf);
	list = read_file(ac, av);
	count_map_size(list, &fdf);
	create_int_matrix(&fdf);
	fill_the_matrix(list, &fdf);
	create_matrix_of_structures(&fdf);
	create_isometric(&fdf);
	open_window(&fdf);
	return (0);
}
