/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mat_of_structures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:18:29 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 14:51:36 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_matrix_of_structures_2(t_fdf *fdf, int *row, int colomn)
{
	while (*row < fdf->row)
	{
		colomn = 0;
		if (!(fdf->triple_matrix[*row] = \
			(t_point **)malloc(sizeof(t_point*) * (fdf->column + 1))))
			return ;
		while (colomn < fdf->column)
		{
			if (!(fdf->triple_matrix[*row][colomn] = \
					(t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triple_matrix[*row][colomn]->x = (colomn + 1) * 30;
			fdf->triple_matrix[*row][colomn]->y = (*row + 1) * 30;
			fdf->triple_matrix[*row][colomn]->z = \
							(fdf->int_matrix[*row][colomn]) * 10;
			colomn++;
		}
		fdf->triple_matrix[*row][colomn] = NULL;
		(*row)++;
	}
}

void		create_matrix_of_structures(t_fdf *fdf)
{
	int		row;

	row = 0;
	if (!(fdf->triple_matrix = \
			(t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	create_matrix_of_structures_2(fdf, &row, 0);
	fdf->triple_matrix[row] = NULL;
}
