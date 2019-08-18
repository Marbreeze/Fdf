/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:16:36 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 13:31:11 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fill_the_matrix(t_fdf_list *list, t_fdf *fdf)
{
	int			row;
	int			column;
	int			counter;
	t_fdf_list	*tmp;

	tmp = list;
	row = 0;
	while (tmp)
	{
		column = 0;
		counter = 0;
		while (tmp->value[counter])
		{
			fdf->int_matrix[row][column] = ft_atoi(&tmp->value[counter]);
			while (tmp->value[counter] != ' ' && tmp->value[counter] != '\0')
				counter++;
			while (tmp->value[counter] == ' ' && tmp->value[counter] != '\0')
				counter++;
			column++;
		}
		row++;
		tmp = tmp->next;
	}
}
