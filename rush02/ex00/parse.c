/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:48:32 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 17:15:54 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

#define BUF_SIZE 10000

char	*ft_read(char *s)
{
	char	buff[BUF_SIZE + 1];
	int		rtn;
	char	*str;
	int		len;
	int		fd;

	len = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((rtn = read(fd, buff, BUF_SIZE)))
		len = len + rtn;
	close(fd);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[0] = '\0';
	fd = open(s, O_RDONLY);
	while ((rtn = read(fd, buff, BUF_SIZE)))
	{
		buff[rtn] = '\0';
		str = ft_strcat(str, buff);
	}
	close(fd);
	return (str);
}

int		count_line(char *s)
{
	int		fd;
	char	buf[1];
	int		ret;
	int		count;

	count = 0;
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buf, 1)))
		if (buf[0] == '\n')
			count++;
	close(fd);
	return (count);
}

int		ft_skip(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

t_dict	*init_dict(char *s)
{
	int		len;
	t_dict	*dict;

	len = count_line(s);
	if (!(dict = (t_dict*)malloc(sizeof(t_dict) * (len + 2))))
		return (0);
	return (dict);
}

t_dict	*parse(char *s)
{
	char	*str;
	int		i;
	int		j;
	t_dict	*dict;

	str = ft_read(s);
	if (!str || !(dict = init_dict(s)))
		return (0);
	i = 0;
	j = -1;
	while (str[i] != '\n' && str[i] != '\0')
	{
		dict[++j].number = ft_strdup(str + i, " :");
		dict[j].len = ft_strlen(dict[j].number);
		i += ft_strlen(dict[j].number) +
			ft_skip(str + i + ft_strlen(dict[j].number));
		if (str[i] != ':')
			return (0);
		i += 1 + ft_skip(str + i + 1);
		dict[j].str = ft_strdup(str + i, "\n");
		i += ft_strlen(dict[j].str) + 1;
	}
	dict[j].len = 0;
	free(str);
	return (dict);
}
