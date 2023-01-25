/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:00:06 by tayou             #+#    #+#             */
/*   Updated: 2023/01/26 07:28:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int	i;
	int	size;

	if (string == 0)
		return (0);
	i = 0;
	while (string[i] != '\0')
		i++;
	size = i;
	return (size);
}

int	ft_strchr(char *string, int c)
{
	int	i;

	if (string == 0)
		return (-1);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *backup, char *buf)
{
	int		buf_size;
	int		i;

	if (buf == NULL)
		buf_size = 0;
	else
		buf_size = ft_strlen(buf);
	backup = (char *) malloc(sizeof(char) * buf_size + 1);
	if (backup == 0)
		return (0);
	i = 0;
	while (buf[i] != '\0')
	{
		backup[i] = buf[i];
		i++;
	}
	backup[i] = '\0';
	return (backup);
}

char	*ft_strjoin(char *backup, char *buf)
{
	char	*new_backup;
	int		backup_size;
	int		buf_size;

	backup_size = ft_strlen(backup);
	buf_size = ft_strlen(buf);
	new_backup = (char *) malloc(sizeof(char) * (backup_size + buf_size) + 1);
	if (new_backup == NULL)
		return (NULL);
	while (*backup != '\0')
	{
		*new_backup = *backup;
		backup++;
		new_backup++;
	}
	while (*buf != '\0')
	{
		*new_backup = *buf;
		buf++;
		new_backup++;
	}
	*new_backup = '\0';
	return (new_backup - backup_size - buf_size);
}

char	*ft_substr(char *backup, int newline_point)
{
	int		size;
	char	*sub_string;
	int		i;
	int		j;

	size = ft_strlen(&backup[newline_point + 1]);
	sub_string = (char *) malloc(sizeof(char) * size + 1);
	if (sub_string == NULL)
		return (NULL);
	i = newline_point + 1;
	j = 0;
	while (backup[i] != '\0')
	{
		sub_string[j] = backup[i];
		j++;
		i++;
	}
	sub_string[j] = '\0';
	return (sub_string);
}
