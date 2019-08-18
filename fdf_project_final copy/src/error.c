/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uamirov <uamirov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:10:57 by uamirov           #+#    #+#             */
/*   Updated: 2019/06/24 12:51:40 by uamirov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	error(char *reason)
{
	write(1, "Error: ", 7);
	ft_putstr(reason);
	ft_putchar('\n');
	exit(1);
}
