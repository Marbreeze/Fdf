/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:20:04 by uamirov           #+#    #+#             */
/*   Updated: 2019/08/18 13:58:21 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_list	*put_in_list(t_fdf_list *list, char *line)
{
	t_fdf_list *new;
	t_fdf_list *begin;

	new = NULL;
	begin = NULL;

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

t_fdf_list *read_file(int ac, char **av, t_fdf_list *list)
{
	int		fd;
	char	*line;

	list = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		if (fd == -1)
			ft_putstr("Invalid file");
		while (get_next_line(fd, &line) == 1)
			list = put_in_list(list, line);
	}
	else
		ft_putstr("too many argument");
	close(fd);
	return (list);
}

void	struct_init(int ac, char **av ,t_fdf *fdf, t_fdf_list *list)
{

	fdf->first = (t_point *)malloc(sizeof(t_point));
	fdf->second = (t_point *)malloc(sizeof(t_point));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->first->z = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->second->z = 0;
	// ft_bzero(&list, sizeof(t_fdf_list));
	list = read_file(ac, av, list);
}

int				main(int ac, char **av)
{
	t_fdf		fdf;
	t_fdf_list	*list;

	list = NULL;
	struct_init(ac, av, &fdf, list);
	// list = read_file(ac, av);
	count_map_size(list, &fdf);
	create_int_matrix(&fdf);
	fill_the_matrix(list, &fdf);
	create_matrix_of_structures(&fdf);
	create_isometric(&fdf);
	open_window(&fdf);
	return (0);
}
