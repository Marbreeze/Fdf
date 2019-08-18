#include "../inc/fdf.h"

int		read_line(t_info *e, char **rows, int i)
{
	char	**columns;
	t_point point;
	int		j;

	if ((columns = ft_strsplit(rows[i], ' ')) == NULL)
		return (-1);
	j = -1;
	while (columns[++j] != 0)
	{
		point.x0 = j;
		point.y0 = i;
		point.x = 0;
		point.y = 0;
		point.z = ft_atoi(columns[j]);
		e->points_tab[i] = ft_realloc(e->points_tab[i], point, j);
	}
	ft_strdel(rows);
	if (!(e->points_tab = realloc_pts(e->points_tab, e->points_tab[i])))
		return (-1);
	return (0);
}

int		read_map(t_info *e)
{
	char	**rows;
	int		i;

	i = 0;
	if ((rows = ft_strsplit(e->map, '\n')) == NULL)
		return (-1);
	if (!(e->points_tab = (t_point**)malloc(sizeof(t_point*))))
		return (-1);
	while (rows[i] != 0)
	{
		read_line(e, rows, i);
		i++;
	}
	e->points_tab[i] = NULL;
	ft_strdel(rows);
	return (0);
}

void	init_info(t_info *e, char *map)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fdf");
	e->map = map;
	e->divpi = M_PI / 6;
	e->c1 = (float)sin(e->divpi);
	e->c2 = (float)cos(e->divpi);
	e->is_iso = 1;
	e->tr = 1000;
	e->td = 100;
	e->piv = 1;
	e->manz = 10;
	e->zmax = 0;
	e->zmin = 0;
	e->ymax = 0;
	e->ymin = 0;
	e->xmax = 0;
	e->xmin = 0;
	e->zoom = 20;
}

int		setup_mlx(char *map)
{
	t_info	e;

	init_info(&e, map);
	if (read_map(&e) != -1 && calc_points(&e) != -1)
	{
		while (e.zoom > 1 && !ft_fit_win(&e))
		{
			e.ymax = 0;
			e.ymin = 0;
			e.xmax = 0;
			e.xmin = 0;
			e.zoom /= 2;
			calc_points(&e);
		}
		mlx_expose_hook(e.win, put_map, &e);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	loop_hook(&e);
	return (0);
}

int		main(int ac, char **argv)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	*map;
	int		ret;

	ret = 1;
	if (ac != 2)
		ft_putstr("Invalid argument count");
	if ((fd = open(argv[1], O_RDONLY)) > 0)
		ft_putstr("Invalid file type");
	if (!(buffer = ft_strnew(1500)))
		ft_putstr("Invalid size");
	if (!(map = ft_strnew(1500)))
		ft_putstr("Invalid size");
	while ((ret = read(fd, buffer, 1500)))
	{
		buffer[ret] = '\0';
		if (ret == -1 || !(tmp = ft_strjoin(map, buffer))
			|| ft_set(tmp, &map, &buffer) == -1)
			return (0);
	}
	ft_strdel(&buffer);
	setup_mlx(map);
}
