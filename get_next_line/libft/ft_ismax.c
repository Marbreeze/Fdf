/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:21:31 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 16:19:22 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ismax(int *s)
{
	int		i;
	int		ans;

	i = 0;
	ans = s[0];
	while (s[i])
	{
		if (s[i] > ans)
			ans = s[i];
		i++;
	}
	return (ans);
}