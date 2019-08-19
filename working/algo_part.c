#include "fdf.h"

void	map_allocation(t_fdf *fdf)
{
	int		x = 0;
	int		y = 0;

	if (!(fdf->triple_iso_mat = (t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	while (y < fdf->row)
	{
		x = 0;
		if (!(fdf->triple_iso_mat[y] = (t_point **)malloc(sizeof(t_point *) * (fdf->column + 1))))
			return ;
		while (x < fdf->column)
		{
			if (!(fdf->triple_iso_mat[y][x] = (t_point *)malloc(sizeof(t_point))))
				return ;
			x++;
		}
		y++;
	}
}

void	create_isometric(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(fdf->triple_iso_mat = (t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	while (y < fdf->row)
	{
		if (!(fdf->triple_iso_mat[y] = (t_point **)malloc(sizeof(t_point *) * (fdf->column + 1))))
			return ;
		x = 0;
		while (x < fdf->column)
		{
			if (!(fdf->triple_iso_mat[y][x] = (t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triple_iso_mat[y][x]->x = 400 + ((fdf->triple_matrix[y][x]->x
			- fdf->triple_matrix[y][x]->y) * cos(0.523599));

			fdf->triple_iso_mat[y][x]->y = 150 + (((fdf->triple_matrix[y][x]->x
			+ fdf->triple_matrix[y][x]->y) * sin(0.523599))
			- fdf->triple_matrix[y][x]->z);

			fdf->triple_iso_mat[y][x]->z = fdf->triple_matrix[y][x]->z;
			x++;
		}
		fdf->triple_iso_mat[y][x] = NULL;
		y++;
	}
	fdf->triple_iso_mat[y] = NULL;
}

void	create_matrix_structure(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(fdf->triple_matrix = (t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	while (y < fdf->row)
	{
		if (!(fdf->triple_matrix[y] = (t_point **)malloc(sizeof(t_point *) * (fdf->column + 1))))
			return ;
		x = 0;
		while (x < fdf->column)
		{
			if (!(fdf->triple_matrix[y][x] = (t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triple_matrix[y][x]->x = (y + 1) * 30;
			fdf->triple_matrix[y][x]->y = (x + 1) * 30;
			fdf->triple_matrix[y][x]->z = (fdf->int_matrix[y][x]) * 10;
			x++;
		}
		fdf->triple_matrix[y][x] = NULL;
		y++;
	}
	create_isometric(fdf);
			// if (!(fdf->triple_iso_mat[y][x] = (t_point *)malloc(sizeof(t_point))))
			// 	return ;
}
	// if (!(fdf->triple_iso_mat = (t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
	// 	return ;
	// while (y < fdf->row)
	// {
	// 	x = 0;
	// 	if (!(fdf->triple_iso_mat[y] = (t_point **)malloc(sizeof(t_point *) * (fdf->column + 1))))
	// 		return ;
