/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:32:09 by kfum              #+#    #+#             */
/*   Updated: 2022/10/03 11:02:36 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Save string.
*/

static void	return_val(char **s, char **line, int i)
{
	char	*temp;

	if ((*s)[i] == '\n')
	{
		*line = ft_strsub(*s, 0, i);
		temp = ft_strdup(&((*s)[i + 1]));
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}	
}

/*
** Check for newline.
** Return 0 if it's EOF.
** Save all contents before newline.
** Save rest of contents after newline to temp.
** Free contents and update.
** If EOF, free contents.
*/

static int	check_line(char **s, char **line)
{
	int		i;

	i = 0;
	while ((*s)[i] != '\n')
	{
		if (!ft_map_check((*s)[i]))
			return (0);
		if ((*s)[i] == '\0')
			return (0);
		i++;
	}
	return_val(s, line, i);
	return (1);
}

/*
** Read contents from file with defined buff size.
** Concatinate or add contents with buff.
** Search for newline. Break out from loop if found.
** Set ret to 1 once break out from loop.
*/

static int	read_file(int fd, char *buff, char **s, char **line)
{
	int				ret;
	char			*temp;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (*s)
		{
			temp = *s;
			*s = ft_strjoin(temp, buff);
			free(temp);
			temp = NULL;
		}
		else
			*s = ft_strdup(buff);
		if (check_line(s, line))
			break ;
	}
	if (ret > 0)
		return (1);
	else
		return (0);
}

/*
** Checking buff size.
** Adding '\0' to the end of the buff.
*/

static char	*buff_value(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		buff[i++] = '\0';
	}
	return (buff);
}

/*
** Read file contents one line at a time.
** Return -1, 0 or 1 depending on the erros or empty file.
** Allocate memory to read the file and store the content.
** Free the temporary memory when it's not needed or reach the end.
** Check ret value(1 or -1) or return 0
*/

int	get_next_line(const int fd, char **line)
{
	static char		*s[FD_SIZE];
	char			*buff;
	int				ret;

	buff = ft_strnew(BUFF_SIZE + 1);
	if (!line || (fd < 0 || fd >= FD_SIZE) || (read(fd, s[fd], 0) < 0) || !buff)
		return (0);
	if (s[fd])
	{
		if (check_line(&s[fd], line))
			return (1);
	}
	buff_value(buff);
	ret = read_file(fd, buff, &s[fd], line);
	free(buff);
	if (ret != 0 || s[fd] == NULL || s[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = s[fd];
	s[fd] = NULL;
	return (1);
}
