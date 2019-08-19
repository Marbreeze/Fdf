#include "fdf.h"

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
	}
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
		fdf.int_matrix = switch_char_to_int(&fdf);
		create_matrix_structure(&fdf);
		open_window(&fdf);
		close (fd);
	}
	return (0);
}