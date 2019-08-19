/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:17:37 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 13:54:49 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_isometric_2(t_fdf *fdf, int *row, int column)
{
	while (*row < fdf->row)
	{
		column = 0;
		if (!(fdf->triple_iso_mat[*row] = \
			(t_point **)malloc(sizeof(t_point*) * (fdf->column + 1))))
			return ;
		while (column < fdf->column)
		{
			if (!(fdf->triple_iso_mat[*row][column] = \
				(t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triple_iso_mat[*row][column]->x = \
							400 + ((fdf->triple_matrix[*row][column]->x \
				- fdf->triple_matrix[*row][column]->y) * cos(0.523599));
			fdf->triple_iso_mat[*row][column]->y = \
				150 + (((fdf->triple_matrix[*row][column]->x \
				+ fdf->triple_matrix[*row][column]->y) * sin(0.523599)) \
				- fdf->triple_matrix[*row][column]->z);
			fdf->triple_iso_mat[*row][column]->z = \
				fdf->triple_matrix[*row][column]->z;
			column++;
		}
		fdf->triple_iso_mat[*row][column] = NULL;
		(*row)++;
	}
}

void		create_isometric(t_fdf *fdf)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	if (!(fdf->triple_iso_mat = \
		(t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	create_isometric_2(fdf, &row, column);
	fdf->triple_iso_mat[row] = NULL;
}
