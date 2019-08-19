/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:20:27 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 12:32:33 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_border_lines(t_fdf *fdf)
{
	int i;

	i = -1;
	while (++i < fdf->row - 1)
	{
		fdf->first->x = fdf->triple_iso_mat[i][fdf->column - 1]->x;
		fdf->first->y = fdf->triple_iso_mat[i][fdf->column - 1]->y;
		fdf->first->z = fdf->triple_iso_mat[i][fdf->column - 1]->z;
		fdf->second->x = fdf->triple_iso_mat[i + 1][fdf->column - 1]->x;
		fdf->second->y = fdf->triple_iso_mat[i + 1][fdf->column - 1]->y;
		fdf->second->z = fdf->triple_iso_mat[i + 1][fdf->column - 1]->z;
		draw_line(fdf);
	}
	i = -1;
	while (++i < fdf->column - 1)
	{
		fdf->first->x = fdf->triple_iso_mat[fdf->row - 1][i]->x;
		fdf->first->y = fdf->triple_iso_mat[fdf->row - 1][i]->y;
		fdf->first->z = fdf->triple_iso_mat[fdf->row - 1][i]->z;
		fdf->second->x = fdf->triple_iso_mat[fdf->row - 1][i + 1]->x;
		fdf->second->y = fdf->triple_iso_mat[fdf->row - 1][i + 1]->y;
		fdf->second->z = fdf->triple_iso_mat[fdf->row - 1][i + 1]->z;
		draw_line(fdf);
	}
}

void	print_figure(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->row - 1)
	{
		j = 0;
		while (j < fdf->column - 1)
		{
			fdf->first->x = fdf->triple_iso_mat[i][j]->x;
			fdf->first->y = fdf->triple_iso_mat[i][j]->y;
			fdf->first->z = fdf->triple_iso_mat[i][j]->z;
			fdf->second->x = fdf->triple_iso_mat[i + 1][j]->x;
			fdf->second->y = fdf->triple_iso_mat[i + 1][j]->y;
			fdf->second->z = fdf->triple_iso_mat[i + 1][j]->z;
			draw_line(fdf);
			fdf->second->x = fdf->triple_iso_mat[i][j + 1]->x;
			fdf->second->y = fdf->triple_iso_mat[i][j + 1]->y;
			fdf->second->z = fdf->triple_iso_mat[i][j + 1]->z;
			draw_line(fdf);
			j++;
		}
		i++;
	}
	print_border_lines(fdf);
}
