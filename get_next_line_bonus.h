/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:48:56 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/03 18:48:58 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*get_line(char *buffer, char **line, int *res);
char	*read_file(int fd, char *buffer, int *nb_letters);
int		find_n(char *buffer, char c);

char	*ft_strndup(char *str, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*copy_after_n(char *str, int start);

size_t	ft_strlen(char const *str);

#endif
