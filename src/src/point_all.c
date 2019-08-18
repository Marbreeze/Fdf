#include "../inc/fdf.h"

t_point			**realloc_pts(t_point **pts, t_point *point)
{
	unsigned int	i;
	unsigned int	nb_pts;
	t_point			**pts_tmp;

	nb_pts = 0;
	while (pts[nb_pts])
		nb_pts++;
	if (!(pts_tmp = (t_point**)malloc(sizeof(t_point*) * (nb_pts + 2))))
		return (NULL);
	i = -1;
	while (++i < nb_pts)
		pts_tmp[i] = pts[i];
	free(pts);
	pts_tmp[i] = point;
	pts_tmp[i + 1] = NULL;
	return (pts_tmp);
}

t_point			*ft_realloc(t_point *old, t_point point, int nb_pts)
{
	t_point			*new;
	int				i;

	if (!(new = (t_point*)malloc(sizeof(t_point) * (nb_pts + 2))))
		return (NULL);
	i = -1;
	while (++i < nb_pts)
		new[i] = old[i];
	new[i] = point;
	ft_bzero((new + i + 1), sizeof(t_point));
	return (new);
}

static int		die(char **buffer, char **stock)
{
	ft_strdel(buffer);
	ft_strdel(stock);
	return (-1);
}

int				ft_set(char *tmp, char **stk, char **buffer)
{
	ft_strdel(stk);
	if (!(*stk = ft_strdup(tmp)))
		return (die(buffer, stk));
	ft_strdel(&tmp);
	return (1);
}
