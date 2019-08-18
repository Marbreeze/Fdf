/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:14:15 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 13:22:26 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		count_map_size(t_fdf_list *list, t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->column = 0;
	fdf->row = 0;
	while (list->value[i])
	{
		if (list->value[i] != ' ' && list->value[i] != '\0')
		{
			fdf->column++;
			while (list->value[i] != ' ' && list->value[i] != '\0')
				i++;
			while (list->value[i] == ' ')
				i++;
		}
	}
	while (list)
	{
		fdf->row++;
		list = list->next;
	}
}
