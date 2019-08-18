#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <sys/types.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "resources/mlx.h"
// # include "resources/mlx_int.h"
// # include "resources/mlx_new_window.h"
# include "libft/libft.h"

# define ABS(x) ((x) < 0 ? (x) * -1 : (x))

typedef struct			s_list_fdf
{
	char				*value;
	struct s_list_fdf	*next;
}						t_fdf_list;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					column;
	int					row;
	int					**int_matrix;
	t_point				***triple_matrix;
	t_point				***triple_iso_mat;
	t_point				*first;
	t_point				*second;

}						t_fdf;

int error_check_function(int ac, char *av, int fd, char *buffer, char *map);
int check_size_function(char *buffer, char *map);
void    error_function(void);

#endif