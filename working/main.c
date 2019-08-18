#include "fdf.h"

void	count_map_size(t_fdf_list *list, t_fdf *fdf)
{
	int i;

	i = 0;
	printf("This is count map size\n");
	while (list->value[i])
	{
		printf("test : value %s\n", list->value);
		if (list->value[i] != ' ' && list->value[i] != '\0')
		{
			fdf->column++;
			while ((list->value[i] != ' ' && list->value[i] != '\0'))
				i++;
			while (list->value[i] == ' ')
				i++;
		}
	}
	printf("test2 : column %d\n", fdf->column);
	while (list)
	{
		fdf->row++;
		list = list->next;
	}
	printf("test3 : row %d\n", fdf->row);
	fdf->int_matrix = create_int_matrix(list, fdf);
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

void fdf_init(int ac, char **av, t_fdf *fdf)
{
	(void)ac;
	(void)av;
	// ft_bzero(&fdf, sizeof(t_fdf));
	// ft_bzero(&list, sizeof(t_fdf_list));
	fdf->first = (t_point *)malloc(sizeof(t_point));
	fdf->second = (t_point *)malloc(sizeof(t_point));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->first->z = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->second->z = 0;
}

int		main(int ac, char **av)
{
	t_fdf		fdf;
	t_fdf_list 	*list;
	char		*line;
	int			fd;

	fd = 0;
	list = NULL;
	if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		fdf_init(ac, av, &fdf);
		while (get_next_line(fd, &line) == 1)
			list = put_in_list(list, line);
		close (fd);
	}
	count_map_size(list, &fdf);
	create_matrix_structure(&fdf);
	open_window(&fdf);
	return (0);
}