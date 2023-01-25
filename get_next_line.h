/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:53 by tayou             #+#    #+#             */
/*   Updated: 2023/01/25 16:48:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);

char		*ft_strjoin(char *string_1, char *string_2);
char		*ft_substr(char *string, int point);
char		*ft_strcpy(char *dst, char *src);
int			ft_strchr(char *string, int c);
int			ft_strlen(char *string);

#endif
