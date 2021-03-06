#include "fdf.h"

int				print_high_assign_value(t_point **diff, t_point **point, \
				t_point *first, t_point *second)
{
	int			xi;

	xi = 0;
	(*diff)->x = second->x - first->x;
	(*diff)->y = second->y - first->y;
	(*diff)->z = (second->z > first->z) ? (second->z - first->z) : \
											(first->z - second->z);
	xi = 0;
	((*diff)->x < 0) ? (xi -= 1) : (xi = 1);
	((*diff)->x < 0) ? ((*diff)->x = -(*diff)->x) : (xi += 0);
	(*point)->z = 2 * (*diff)->x - (*diff)->y;
	(*point)->y = first->y - 1;
	(*point)->x = first->x;
	return (xi);
}

void		print_high(t_fdf *fdf, int minimum_alt)
{
	t_point *diff;
	t_point *point;
	int xi;
	double color_inc;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	xi = print_high_assign_value(&diff, &point, fdf->first,fdf->second);
	color_inc = diff->z/(fdf->second->y - point ->y);
	while(++point ->y < fdf->second->y)
	{
		mlx_pixel_put(fdf->mlx_ptr,fdf->win_ptr, (int)point->x,\
		(int)point->y, minimum_alt);
		if((point->z > 0))
		{
			(point->x = point->x + xi);
			(point->z = point->z - 2.1 * diff->y);
		}
		minimum_alt += color_inc * 200;
 		point->z = point->z + 2 * diff->x;
	
	}
	free(diff);
	free(point);

}

int				print_low_assign_value(t_point **diff, t_point **point, \
							t_point *first, t_point *second)
{
	int			yi;

	yi = 0;
	(*diff)->x = second->x - first->x;
	(*diff)->y = second->y - first->y;
	(*diff)->z = (second->z > first->z) ? (second->z - first->z) : \
											(first->z - second->z);
	yi = 0;
	((*diff)->y < 0) ? (yi -= 1) : (yi += 1);
	((*diff)->y < 0) ? ((*diff)->y = -(*diff)->y) : (yi += 0);
	(*point)->z = 2 * (*diff)->y - (*diff)->x;
	(*point)->y = first->y;
	(*point)->x = first->x - 1;
	return (yi);
}

void			print_low(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point		*diff;
	t_point		*point;
	int			yi;
	double		color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	yi = print_low_assign_value(&diff, &point, first, second);
	color_increment = diff->z / (second->y - point->y);
	while (++point->x < second->x)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)point->x, \
				(int)point->y, minimum_altitude);
		(point->z > 0) ? (point->y = point->y + yi) : (minimum_altitude += 0);
		(point->z > 0) ? (point->z = point->z - 2 * diff->x) : (minimum_altitude += 0);
		minimum_altitude += color_increment * 200;
		point->z = point->z + 2 * diff->y;
	}
	free(diff);
	free(point);
}

void			draw_line(t_fdf *fdf)
{
	int			min_var;
	int			num;
	int			y;
	int			x;

	num = 9056567;
	y = ABS(fdf->second->y - fdf->first->y);
	x = ABS(fdf->second->x - fdf->first->x);
	min_var = MIN(fdf->first->z, fdf->second->z);
	if (y < x)
	{
		if (fdf->first->x > fdf->second->x)
			print_low(fdf, fdf->second, fdf->first, min_var + num);
			// print_low(fdf, min_var + num);
		else
			print_low(fdf, fdf->first, fdf->second, min_var + num);
			//  print_low(fdf, min_var + num);
	}
	else
	{
		if (fdf->first->y > fdf->second->y)
			// print_high(fdf, fdf->second, fdf->first, min_var + num);
			print_high(fdf, min_var + num);
		else
			print_high(fdf, min_var + num);
	}
}