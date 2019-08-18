/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:15:26 by uamirov           #+#    #+#             */
/*   Updated: 2019/05/16 20:30:27 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_int_matrix(t_fdf *fdf)
{
	int		k;

	k = 0;
	if (!(fdf->int_matrix = (int**)malloc(sizeof(int*) * fdf->row)))
		return ;
	while (k < fdf->row)
	{
		if (!(fdf->int_matrix[k] = (int*)malloc(sizeof(int) * fdf->column)))
			return ;
		k++;
	}
}
