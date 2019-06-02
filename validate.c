/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:33:24 by mstratu           #+#    #+#             */
/*   Updated: 2019/06/01 21:50:58 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static size_t	ft_count(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			cnt++;
		s++;
	}
	return (cnt);
}
int     get_counter(char *str, int *width, int *height)
{
    char *n_line;
    int     fd;
    int     h = 0;


    fd = open(str, O_RDONLY);

    while(get_next_line(fd, &n_line) == 1)
    {
        *width = ft_count(n_line, ' ');
        h++;
    }
    *height = h;
    close(fd);
    return (0);
}


int     read_n_check(char *str, t_fdf *fdf)
{
    char    *line;
    int     j;
    char    **tab;
    int     i;
    int     fd;


    if(get_counter(str, &fdf->width, &fdf->height))
    {
        return (-1);
    }

    fd = open(str, O_RDONLY);
    fdf->array = (int**)malloc(sizeof(int*) * fdf->height);
    i = 0;
    while(get_next_line(fd, &line) == 1)
    {
       fdf->array[i] = malloc(sizeof(int) * fdf->width);
       tab = ft_strsplit(line, ' ');
       j = 0; //each elem in my line
       while(j < fdf->width)
       {
           fdf->array[i][j] = ft_atoi(tab[j]); //i is nur of line
           j++;
       }
       i++;
    }
    close(fd);
    // printf("%d %d %d\n", fdf->width, fdf->height, i);
    // for (i = 0; i < fdf->height; i++)
    // {
    //     for (j = 0; j < fdf->width; j++)
    //         printf("%d ", fdf->array[i][j]);
    //     printf("\n");
    // }
    return (-1);
}
