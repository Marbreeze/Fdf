#include "fdf.h"

// void	count_map_size(t_fdf_list *list, t_fdf *fdf)
// {
// 	int i;

// 	i = 0;
// 	printf("This is count map size\n");
// 	while (list->value[i])
// 	{
// 		if (list->value[i] != ' ' && list->value[i] != '\0')
// 		{
// 			fdf->column++;
// 			while ((list->value[i] != ' ' && list->value[i] != '\0'))
// 				i++;
// 			while (list->value[i] == ' ')
// 				i++;
// 		}
// 		printf("test : value %s\n", list->value);
// 	}
// 	printf("test2 : column %d\n", fdf->column);
// 	while (list)
// 	{
// 		fdf->row++;
// 		list = list->next;
// 	}
// 	printf("test3 : row %d\n", fdf->row);
// 	fdf->int_matrix = create_int_matrix(list, fdf);
// }



void fdf_init(t_fdf *fdf)
{
	fdf->first = (t_point *)malloc(sizeof(t_point));
	fdf->second = (t_point *)malloc(sizeof(t_point));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->first->z = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->second->z = 0;
}

char	**get_info(int fd, t_fdf *fdf)
{
	char	*line;
	char	*tmp;
	char	**split;
	int		count;

	count = 0;
	split = NULL;
	tmp = ft_strnew(1);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(tmp, line);
		tmp = ft_strjoin(tmp, "\n");
	}
	split = ft_strsplit(tmp, '\n');
	while (split[0][count])
	{
		if (split[0][count] != ' ' && split[0][count] != '\0')
			fdf->column++;
		count++;
	}
	count = -1;
	while (split[++count])
		fdf->row++;
	return (split);
}

void	array_allocation(t_fdf *fdf)
{
	int			i;

	i = 0;
	if (!(fdf->int_matrix = (int **)malloc(sizeof(int *) * fdf->row)))
		return ;
	while (i < fdf->row)
	{
		if (!(fdf->int_matrix[i] = (int *)malloc(sizeof(int) * fdf->column)))
			return ;
		i++;
		// fdf->int_matrix[i][fdf->column] = 0;		
	}
	// fdf->int_matrix[i] = 0;
}

int		**switch_char_to_int(t_fdf *fdf)
{
	int			y;
	int			x;
	int			count;
	char		*tmp;

	array_allocation(fdf);
	y = 0;
	while (y < fdf->row)
	{
		tmp = ft_strnew(1);
		tmp = ft_strjoin(tmp, fdf->value[y]);
		x = 0;
		count = 0;
		while (x < fdf->column)
		{
			fdf->int_matrix[y][x] = ft_atoi(&tmp[count]);
			while (tmp[count] != ' ' && tmp[count] != '\0')
				count++;
			while (tmp[count] == ' ' && tmp[count] != '\0')
				count++;
			x++;
		}
		free(tmp);
		y++;
	}
	return (fdf->int_matrix);
}

int		main(int ac, char **av)
{
	t_fdf		fdf;
	int			fd;
	// int			i = 0;

	fd = 0;
	ft_bzero(&fdf, sizeof(t_fdf));
	if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		fdf_init(&fdf);
		fdf.value = get_info(fd, &fdf);
		// printf("%s\n", fdf.value[1]);
		// printf("row : %d\ncolumn : %d\n", fdf.row, fdf.column);
		fdf.int_matrix = switch_char_to_int(&fdf);
		create_matrix_structure(&fdf);
		open_window(&fdf);
		close (fd);
	}
	return (0);
}

		// while (i < fdf.row)
		// {
		// 	printf("value test : %s\n", fdf.value[i]);
		// 	i++;
		// }