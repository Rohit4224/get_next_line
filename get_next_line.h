/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:53:09 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/31 17:25:59 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stddef.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *b);
char	*ft_strchr(char *t, int c);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_read_n_save(int fd, char *save);

#endif
