/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:00:06 by tayou             #+#    #+#             */
/*   Updated: 2023/01/26 05:56:36 by tayou            ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*dst;
	int		src_size;
	int		i;

	if (src == NULL)
		src_size = 0;
	else
		src_size = ft_strlen(src);
	dst = (char *) malloc(sizeof(char) * src_size + 1);
	if (dst == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *backup, char *buf)
{
	char	*new_backup;
	int		backup_size;
	int		buf_size;
	int		total_size;

	backup_size = ft_strlen(backup);
	buf_size = ft_strlen(buf);
	total_size = backup_size + buf_size;
	new_backup = (char *) malloc(sizeof(char) * total_size + 1);
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
