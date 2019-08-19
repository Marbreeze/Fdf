#include "fdf.h"

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
		x = 0;
		if (!(fdf->triple_iso_mat[y] = (t_point **)malloc(sizeof(t_point *) * (fdf->column + 1))))
			return ;
		while (x < fdf->column)
		{
			if (!(fdf->triple_iso_mat[x][y] = (t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triple_iso_mat[y][x]->x = 400 + ((fdf->triple_matrix[y][x]->x - fdf->triple_matrix[y][x]->y) * cos(0.523599));
			fdf->triple_iso_mat[y][x]->y = 150 + (((fdf->triple_matrix[y][x]->x + fdf->triple_matrix[y][x]->y) * sin(0.523599)) - fdf->triple_matrix[y][x]->z);
			fdf->triple_iso_mat[y][x]->z = fdf->triple_matrix[y][x]->z;
			x++;
		}
		fdf->triple_iso_mat[y][x] = NULL;
		y++;
	}
}

void	create_matrix_structure(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(fdf->triple_matrix = (t_point ***)malloc(sizeof(t_point **) * (fdf->row + 1))))
		return ;
	while (x < fdf->row)
	{
		x = 0;
		if (!(fdf->triple_matrix[x] = (t_point **)malloc(sizeof(t_point *) * (fdf->column + 1))))
			return ;
		while (x < fdf->column)
		{
			if (!(fdf->triple_matrix[x][y] = (t_point *)malloc(sizeof(t_point))))
				return ;
			fdf->triple_matrix[x][y]->x = (y + 1) * 30;
			fdf->triple_matrix[x][y]->y = (x + 1) * 30;
			fdf->triple_matrix[x][y]->z = (fdf->int_matrix[x][y]) * 10;
			x++;
		}
		fdf->triple_matrix[x][y] = NULL;
		y++;
	}
	create_isometric(fdf);
}