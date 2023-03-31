/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:34:59 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/31 19:52:22 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *save)
{
	int		r;
	char	*stri;

	r = 0;
	if (save[r] == '\0')
		return (NULL);
	while (save[r] != '\0' && save[r] != '\n')
		r++;
	if (save[r] == '\n')
		r++;
	stri = (char *)malloc(sizeof(char) * (r + 1));
	r = 0;
	while (save[r] != '\0' && save[r] != '\n')
	{
		stri[r] = save[r];
		r++;
	}
	if (save[r] == '\n')
	{
		stri[r] = save[r];
		r++;
	}
	stri[r] = '\0';
	return (stri);
}

char	*ft_save(char *save)
{
	int		p;
	int		o;
	char	*st;

	p = 0;
	while (save[p] != '\0' && save[p] != '\n')
		p++;
	if (save[p] == '\0')
	{
		free(save);
		return (NULL);
	}
	st = (char *)malloc((sizeof(char) *(ft_strlen(save) - p + 1)));
	if (st == NULL)
		return (NULL);
	p++;
	o = 0;
	while (save[p] != '\0')
	{
		st[o++] = save[p++];
	}
	st[o] = '\0';
	free(save);
	return (st);
}

char	*ft_read_n_save(int fd, char *save)
{
	char	*buff;
	int		readb;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	readb = 1;
	while (ft_strchr(save, '\n') == NULL && readb != 0)
	{
		readb = read(fd, buff, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readb] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	if (*save == 0)
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (save[fd] != NULL)
		{
			free(save[fd]);
			save[fd] = NULL;
		}
		return (NULL);
	}
	save[fd] = ft_read_n_save(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = ft_get_line(save[fd]);
	if (line == 0)
	{
		free(line);
		return (0);
	}
	save[fd] = ft_save(save[fd]);
	return (line);
}

/* #include <stdio.h> 	

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s", line, string);
			free(string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}
 */