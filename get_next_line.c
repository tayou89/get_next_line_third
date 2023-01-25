/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 05:48:05 by tayou             #+#    #+#             */
/*   Updated: 2023/01/26 07:26:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_backup(char *backup, char *buf);
static char	*get_line(char *backup);
static char	*renewal_backup(char *backup);

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		backup = get_backup(backup, buf);
		if (ft_strchr(backup, '\n') >= 0)
			break ;
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	line = get_line(backup);
	backup = renewal_backup(backup);
	return (line);
}

static char	*get_backup(char *backup, char *buf)
{
	if (buf == NULL)
		return (NULL);
	if (backup == NULL)
		backup = ft_strdup(backup, buf);
	else
		backup = ft_strjoin(backup, buf);
	return (backup);
}

static char	*get_line(char *backup)
{
	char	*string;
	int		backup_size;
	int		i;

	if (backup == NULL)
		return (NULL);
	backup_size = ft_strlen(backup);
	string = (char *) malloc(sizeof(char) * backup_size + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (backup[i] != '\0')
	{
		string[i] = backup[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static char	*renewal_backup(char *backup)
{
	int		newline_point;
	char	*new_backup;

	newline_point = ft_strchr(backup, '\n');
	if (newline_point >= 0)
		new_backup = ft_substr(backup, newline_point);
	else
		new_backup = NULL;
	return (new_backup);
}
