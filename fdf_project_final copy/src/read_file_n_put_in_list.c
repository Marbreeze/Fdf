/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_n_put_in_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:20:33 by uamirov           #+#    #+#             */
/*   Updated: 2019/08/18 13:56:01 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

// t_fdf_list		*put_in_list(t_fdf_list *list, char *line)
// {
// 	t_fdf_list	*new;
// 	t_fdf_list	*begin;

// 	new = NULL;
// 	begin = NULL;
// 	if (!list)
// 	{
// 		new = (t_fdf_list*)malloc(sizeof(t_fdf_list));
// 		new->value = ft_strdup(line);
// 		new->next = NULL;
// 		return (new);
// 	}
// 	begin = list;
// 	new = (t_fdf_list*)malloc(sizeof(t_fdf_list));
// 	new->value = ft_strdup(line);
// 	new->next = NULL;
// 	while (begin->next)
// 		begin = begin->next;
// 	begin->next = new;
// 	return (list);
// }

// t_fdf_list		*read_file(int argc, char **av)
// {
// 	int			fd;
// 	char		*line;
// 	t_fdf_list	*list;

// 	list = NULL;
// 	if (argc == 2)
// 	{
// 		fd = open(av[1], O_RDWR);
// 		if (fd == -1)
// 			error("Invalid file");
// 		while (get_next_line(fd, &line) == 1)
// 			list = put_in_list(list, line);
// 	}
// 	else
// 		error("Too many arguments");
// 	if (argc == 2)
// 		close(fd);
// 	return (list);
// }
