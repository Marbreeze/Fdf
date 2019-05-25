/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:54:28 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/22 14:31:40 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				checkfor_new(char **temp, char **line, int fd)
{
	int			len;
	char		*valdo;

	len = 0;
	while (temp[fd][len] != '\n' && temp[fd][len] != '\0')
		len++;
	if (temp[fd][len] == '\n')
	{
		*line = ft_strsub(temp[fd], 0, len);
		valdo = ft_strdup(&temp[fd][len + 1]);
		ft_strdel(&temp[fd]);
		temp[fd] = valdo;
	}
	else
	{
		*line = ft_strdup(temp[fd]);
		ft_strdel(&temp[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*temp[FD_MAX];
	char		*text_temp;
	int			num;

	if (!line || fd < 0 || fd > FD_MAX || (read(fd, buf, 0) < 0)
	|| BUFF_SIZE <= 0)
		return (-1);
	if (!temp[fd])
	{
		temp[fd] = ft_strnew(1);
	}
	while ((num = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[num] = '\0';
		text_temp = ft_strjoin(temp[fd], buf);
		ft_strdel(&temp[fd]);
		temp[fd] = text_temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (temp[fd][0] == '\0')
		return (0);
	return (checkfor_new(temp, line, fd));
}
