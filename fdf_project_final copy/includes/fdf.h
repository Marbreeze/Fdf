/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:12:14 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 13:34:13 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct			s_list_fdf
{
	char				*value;
	struct s_list_fdf	*next;
}						t_fdf_list;

/*
** x = row;
** y = col;
** z = value;
*/

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

/*
** i = 19 in 42 map;
** j = 11 in 42 map;
*/

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

void					make_fdf_values_to_zero(t_fdf *fdf);
t_fdf_list				*read_file(int argc, char **av);
void					error(char *reason);
t_fdf_list				*put_in_list(t_fdf_list *list, char *line);
void					count_map_size(t_fdf_list *list, t_fdf *fdf);
void					create_int_matrix(t_fdf *fdf);
void					fill_the_matrix(t_fdf_list *list, t_fdf *fdf);
void					create_matrix_of_structures(t_fdf *fdf);
void					create_isometric(t_fdf *fdf);
void					open_window(t_fdf *fdf);
void					print_figure(t_fdf *fdf);
void					print_border_lines(t_fdf *fdf);
void					draw_line(t_fdf *fdf);
int						ft_abs(double num);
void					print_high(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude);
int						print_high_assign_value(t_point **diff, \
					t_point **point, t_point *first, t_point *second);
void					print_low(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude);
int						print_low_assign_value(t_point **diff, \
					t_point **point, t_point *first, t_point *second);

#endif
