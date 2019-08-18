#include <libft.h>
#include "fdf.h"

int		**fill_the_matrix(t_fdf_list *list, t_fdf *fdf)
{
	int		x;
	int		y;
	int		counter;

	y = 0;
	while (list->value != '\0')
	{
		x = 0;
		counter = 0;
		while (list->value[counter])
		{
			fdf->int_matrix[y][x] = ft_atoi(list->value[counter]);
			while(list->value[counter] != '\0')
				counter++;
			// while (list->value[counter] != ' ' && list->value[counter] != '\0')
			// 	counter++;
			// while (list->value[counter == ' '] && list->value[counter != '\0'])
			// 	counter++;
			x++;
		}
		y++;
		list->next;
	}
	return (fdf->int_matrix);
}

int		**create_int_matrix(t_fdf_list *list, t_fdf *fdf)
{
	int		i;

	i = 0;
	if (!(fdf->int_matrix = (int **)malloc(sizeof(int *) * fdf->row)))
		return (1);
	while (i < fdf->row)
	{
		if (!(fdf->int_matrix[i] = (int *)malloc(sizeof(int) * fdf->column)))
			return (1);
		i++;
	}
	fdf->int_matrix = fill_the_matrix(&list, &fdf);
	return (fdf->int_matrix);
}

void	count_map_size(t_fdf_list *list, t_fdf *fdf)
{
	int i;

	i = 0;
	while (list->value[i])
	{
		if (list->value[i] != ' ' && list->value[i] != '\0')
		{
			fdf->column++;
			while ((list->value[i] != ' ' && list->value[i] != '\0'))
				i++;
			while (list->value[i] == ' ')
				i++;
		}
	}
	while (list)
	{
		fdf->row++;
		list = list->next;
	}
	fdf->int_matrix = create_int_matrix(&list, &fdf);
}

t_fdf_list *put_in_list(t_fdf_list *list, char *line)
{
	t_fdf_list *new;
	t_fdf_list *begin;

	ft_bzero(&new, sizeof(t_fdf_list));
	ft_bzero(&begin, sizeof(t_fdf_list));
	if (!list)
	{
		new = (t_fdf_list *)malloc(sizeof(t_fdf_list));
		new->value = ft_strdup(line);
		new->next = NULL;
		return (new);
	}
	begin = list;
	new = (t_fdf_list *)malloc(sizeof(t_fdf_list));
	new->value = ft_strdup(line);
	new->next = NULL;
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	return (list);
}

t_fdf_list *fdf_init(int ac, char **av, t_fdf_list *list, t_fdf *fdf)
{
	ft_bzero(&fdf, sizeof(t_fdf));
	ft_bzero(&list, sizeof(t_fdf_list));
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
	create_isometric(&fdf);
}


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

int		main(int ac, char **av)
{
	t_fdf		fdf;
	t_fdf_list 	*list;
	char		*line;
	int			fd;

	fd = 0;
	if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		fdf_init(ac, av, &list, &fdf);
		while (get_next_line(fd, &line) == 1)
			list = put_in_list(list, line);
		close (fd);
	}
	count_map_size(&list, &fdf);
	create_matrix_structure(&fdf);
	open_window(&fdf);
	return (0);
}