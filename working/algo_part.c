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

int		**fill_the_matrix(t_fdf_list *list, t_fdf *fdf)
{
	int		x;
	int		y;
	int		counter;

	y = 0;
	while (list->value)
	{
		x = 0;
		counter = 0;
		while (list->value[counter])
		{
			fdf->int_matrix[y][x] = ft_atoi(&list->value[counter]);
			// while(list->value[counter] != '\0')
			// 	counter++;
			while (list->value[counter] != ' ' && list->value[counter] != '\0')
				counter++;
			while (list->value[counter == ' '] && list->value[counter != '\0'])
				counter++;
			x++;
		}
		y++;
		list = list->next;
	}
	return (fdf->int_matrix);
}

int		**create_int_matrix(t_fdf_list *list, t_fdf *fdf)
{
	int		i;

	i = 0;
	// if (!(fdf->int_matrix = (int **)malloc(sizeof(int *) * fdf->row)))
	// 	return ;
	fdf->int_matrix = (int **)malloc(sizeof(int *) * fdf->row);
	while (i < fdf->row)
	{
		// if (!(fdf->int_matrix[i] = (int *)malloc(sizeof(int) * fdf->column)))
		// 	return (1);
		fdf->int_matrix[i] = (int *)malloc(sizeof(int) * fdf->column);
		i++;
	}
	fdf->int_matrix = fill_the_matrix(list, fdf);
	return (fdf->int_matrix);
}