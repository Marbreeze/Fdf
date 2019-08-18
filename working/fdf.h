#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <sys/types.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# define WIN_X 2000
# define WIN_Y 140

typedef struct s_line
{
    float   cp1;
    float   cp2;
    int     dx;
    int     dy;
    int     x;
    int     y;
}               t_line;

typedef struct			s_list_fdf
{
	char				*value;
	struct s_list_fdf	*next;
}						t_store_list;

typedef struct s_point
{
    int     x0;
    int     y0;
    int     x;
    int     y;
    int     z;
}               t_point;

typedef struct s_coor_minmax
{
    int     maxz;
    int     minz;
    int     maxx;
    int     minx;
    int     maxy;
    int     miny;
}               t_coor_minmax;

typedef	struct	s_info
{
	void	*mlx;
	void	*win;
	float	c1;
	float	c2;
	float	divpi;
	int		is_iso;
	float	piv;
	int		zoom;
	int		manz;
	int		tr;
	int		td;
	int		is_decr;
    t_coor_minmax coor;
	t_point	**points_tab;
}				t_info;


int error_check_function(int ac, char *av, int fd, char *buffer, char *map);
int check_size_function(char *buffer, char *map);
void    error_function(void);

#endif