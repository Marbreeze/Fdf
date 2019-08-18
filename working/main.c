#include <libft.h>
#include "fdf.h"


void	init_info(t_info *e, char *map)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fdf");
	e->divpi = M_PI / 6;
	e->c1 = (float)sin(e->divpi);
	e->c2 = (float)cos(e->divpi);
	e->is_iso = 1;
	e->tr = 1000;
	e->td = 100;
	e->piv = 1;
	e->manz = 10;
	e->zoom = 20;
}

t_store_list		*put_in_list(t_fdf_list *list, char *line)
{
	t_store_list	*new;
	t_store_list	*begin;

	new = ft_bzero(&new, sizeof(t_store_list));
	begin = ft_bzero(&begin, sizeof(t_store_list));
	if (!list)
	{
		new = (t_fdf_list*)malloc(sizeof(t_fdf_list));
		new->value = ft_strdup(line);
		new->next = NULL;
		return (new);
	}
	begin = list;
	new = (t_store_list*)malloc(sizeof(t_store_list));
	new->value = ft_strdup(line);
	new->next = NULL;
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	return (list);
}

t_store_list *read_map(t_info *e, char *map, int ac, char *av)
{
    int     fd;
    char    *line;
    t_store_list  *list;

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        error_function();
    while (get_next_line(fd, &line))
        list = put_in_list(list, line);
    return (list);
}

int		calc_points(t_info *e)
{
	int		i;
	int		j;
	t_point	**points;
	t_point	nullpt;

	ft_bzero(&nullpt, sizeof(t_point));
	i = 0;
	if ((points = e->points_tab) == NULL)
		return (-1);
	while (points[i] != '\0')
	{
		j = 0;
        while (point[i][j] != '\0')
        {
            ft_memcmp(&points[i][j], &nullpt, sizeof(t_point));
            j++;
        }
        i++;
	}
	return (0);
}

int		setup_mlx(char *map, t_store_list *e, int ac, char *av)
{
    t_info      *marina;

	init_info(&mairna, map);
    ft_bzero(&marina->coor, sizeof(t_coor_minmax));
    e = read_map(&e, map, ac ,av)
	if (calc_points(&marina) != -1)
	{
		while (e->zoom > 1 && !ft_fit_win(&e))
		{
			e->ymax = 0;
			e->ymin = 0;
			e->xmax = 0;
			e->xmin = 0;
			e->zoom /= 2;
			calc_points(&e);
		}
		mlx_expose_hook(e.win, put_map, &e);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	loop_hook(&e);
	return (0);
}


int main(int ac, char **av)
{
    int     fd;
    char    *buffer;
    char    *tmp;
    char    *map;
    int     ret;
    t_store_list *e;

    e = ft_bzero(*e, sizeof(t_store_list));
    ret = 0;
    fd = 0;
    error_check_function(ac, av, fd, buffer, map);
    while ((ret = read(fd, buffer, 1500)))
    {
        buffer[ret] = '\0';
        if (ret == -1 || tmp = ft_strjoin(map, buffer))
        || ft_set(tmp, &map, &buffer) == -1)
        return (0);
    }
    free(buffer);
    setup_mlx(map, &e, ac, av);
    return (0);
    // if (ac != 2 && (fd = open(av[1], O_RDONLY) > 0)
    //     error_function();
    // if (check_size_function(buffer, map) == EXIT_FAILURE)
    //     error_funtion();
}