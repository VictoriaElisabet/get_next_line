/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:56:14 by vgrankul          #+#    #+#             */
/*   Updated: 2019/11/25 11:26:05 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	get_line(char **str, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(&str[fd][i + 1])))
			return (-1);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (!(*line = ft_strsub(str[fd], 0, i)))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	return_value(char **str, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
		return (0);
	else
		return (get_line(str, line, fd));
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		arr[BUFF_SIZE + 1];
	char		*tmp;
	static char	*str[FD_MAX];
	int			i;

	i = 0;
	if (fd < 0 || line == NULL)
	{
		return (-1);
	}
	while ((ret = read(fd, arr, BUFF_SIZE)) > 0)
	{
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(0)))
				return (-1);
		arr[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], arr)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(arr, '\n'))
			break ;
	}
	return (return_value(str, line, fd, ret));
}
