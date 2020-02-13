/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReadAndBuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:00:36 by hana              #+#    #+#             */
/*   Updated: 2020/02/13 08:22:07 by hana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"
#include <stdio.h>

char	*ft_SetMaptemp(int i, char *buff, char *cMaptemp)
{
	int		j;

	while (buff[i] != '\n')
		i++;
	j = 0;
	i++;
	while (buff[i])
	{
		cMaptemp[j] = buff[i];
		i++;
		j++;	
	}
	cMaptemp[j] = 0;
	return (cMaptemp);
}

void	ft_SetMapInfo(int i, int j, int k, int t, int x, char *buff)
{
	while (buff[j] != '\n')
		j++;
	ft_MakeinfoC(j, buff);
	g_infoN = 0;
	while (i < j - 3)
	{
		g_infoN = (g_infoN * 10) + (buff[i] - '0');
		i++;
	}
}

char	*ft_Setbuff(char *argv)
{
	int		fd;
	int		rd_size;
	int		i;
	char	*buff;

	i = 0;
	fd = open(argv, O_RDONLY);
	buff = (char *)malloc(sizeof(char) * 1001);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	else if (fd > 0)
	{
		rd_size = read(fd, buff, 1000);
		close (fd);
		return (buff);
	}
	return (0);
}

int		ft_ReadAndBuff(int argc, char **argv)
{
	char	*buff;
	char	*cMaptemp;
	char	**vector;
	int		i;

	i = 0;
	cMaptemp = (char *)malloc(sizeof(char) * MAX_COLS + 1);
	vector = (char **)malloc(sizeof(char *) * argc);
	while (i < argc)
	{
		vector[i] = (char *)malloc(sizeof(char) * SIZE + 1);
		i++;
	}
	vector = argv;
	buff = ft_Setbuff(vector[1]);//파일 읽고 버프에 저장
	if (ft_JoongBokPrintable(0, 0, 0, buff) == 0)
		return (0);
	ft_SetMapInfo(0, 0, 0, 0, 0, buff);//버프 첫줄로 맵인포 저장
	cMaptemp = ft_SetMaptemp(0, buff, cMaptemp);//버프 나머지로 맵 임시저장
	ft_SetCharMap(cMaptemp, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**vector;

	i = 0;
	vector = (char **)malloc(sizeof(char *) * argc);
	while (i < argc)
	{
		vector[i] = (char *)malloc(sizeof(char) * SIZE + 1);
		i++;	
	}
	vector = argv;
	if (ft_ReadAndBuff(argc, vector) == 0)
	{
		write(1, "map error?\n", 11);
		return (0);
	}
	return(0);
}
