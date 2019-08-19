#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <sys/types.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

// # define MARINA 9056567
# define ABS(x) ((x) < 0 ? (x) * -1 : (x))
# define MIN(a, b) ((a > b) ? b : a)
//1524

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_mlx;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_fdf
{
	t_mlx				mlx;
	void				*mlx_ptr;
	void				*win_ptr;
	int					column;
	int					row;
	int					**int_matrix;
	char				**value;
	t_point				***triple_matrix;
	t_point				***triple_iso_mat;
	t_point				*first;
	t_point				*second;

}						t_fdf;

int 	error_check_function(int ac, char *av, int fd, char *buffer, char *map);
int 	check_size_function(char *buffer, char *map);
void    error_function(void);
void	print_border_lines(t_fdf *fdf);
void	print_figure(t_fdf *fdf);
void	open_window(t_fdf *fdf);
int		esc(int key);
int		close_w(void *param);
void	create_matrix_structure(t_fdf *fdf);
void	create_isometric(t_fdf *fdf);
int		print_low_assign_value(t_point **diff, t_point **point, t_point *first, t_point *second);
// void	print_low(t_fdf *fdf, t_point *first, t_point *second, int minimum_altitude);
void			print_low(t_fdf *fdf, int min);
int		print_high_assign_value(t_point **diff, t_point **point, t_point *first, t_point *second);
void	print_high(t_fdf *fdf, t_point *first, t_point *second, int minimum_altitude);
void	draw_line(t_fdf *fdf);

#endif