
#ifndef FDF_H
# define FDF_H

# include "get_next_line/libft/libft.h"
// # include "fdfStuff/minilibx_macos/mlx.h"
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef struct      s_fdf
{
    int     **array;
    int     width;
    int     height;
    int     color;


}                   t_fdf;

int     read_n_check(char *str, t_fdf *fdf);

#endif