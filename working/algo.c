#include "fdf.h"

int		ft_fit_win(t_info *e)
{
	int is_fit;

	is_fit = 1;
	if (e->xmax - e->xmin > WIN_X || e->ymax - e->ymin > WIN_Y)
		is_fit = 0;
	else
	{
		e->tr = (WIN_X - (float)(e->xmax - e->xmin)) / 2 + ABS(e->xmin);
		e->td = (WIN_Y - (float)(e->ymax - e->ymin)) / 2 + ABS(e->ymin);
	}
	return (is_fit);
}
