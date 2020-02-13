/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetCharMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:07:21 by hana              #+#    #+#             */
/*   Updated: 2020/02/13 08:23:22 by hana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

int		ft_SetnWidth(int i, char *cMaptemp)
{
	while (cMaptemp[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	**ft_SetMap(char **cMap, char *cMaptemp, int nHeight, int nWidth)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	cMap = (char **)malloc(sizeof(char *) * nHeight);
	while (i < nHeight)
	{	
		cMap[i] = (char *)malloc(sizeof(char) * 1000);
		i++;
	}
	i = 0;
	while (i < nHeight)
	{
		j = 0;
		while(cMaptemp[k] != '\n')
		{
			cMap[i][j] = cMaptemp[k];
			j++;
			k++;
		}
		cMap[i][j] = 0;
		i++;
		k++;
	}
	return (cMap);
}

int		ft_CheckMapChar(char **Map, int nWidth, int nHeight)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nWidth)
	{
		while (j < nHeight)
		{
			if (Map[j][i] != g_infoC[0] && Map[j][i] != g_infoC[1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_CheckMapWidth(int nHeight, int nWidth, char **cMap)
{
	int		i;
	int		j;

	i = 0;
	while (i < nHeight)
	{
		j = 0;
		while (cMap[i][j] != 0)
		{
			j++;
		}
		if (cMap[i][j] == 0 && j != nWidth)
			return (0);
		if (j == nWidth && cMap[i][j] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_SetCharMap(char *cMaptemp, int i)
{
	int		nWidth;
	int		nHeight;
	int		nRes;
	int		**nMap;
	char	**cMap;
	
	nHeight = g_infoN;
	nWidth = ft_SetnWidth(0, cMaptemp);
	nMap = (int **)malloc(sizeof(int *) * nHeight);
	while (i < nHeight)
	{
		nMap[i] = (int *)malloc(sizeof(int) * 1000);
		i++;
	}
	cMap = ft_SetMap(cMap, cMaptemp, nHeight, nWidth);
	if (ft_CheckMapWidth(nHeight, nWidth, cMap) == 0)
		write(1, "map error\n", 10);
	nRes = ft_CheckMapChar(cMap, nWidth, nHeight);
	if (nRes == 0)
		write(1, "map error\n", 10);
	nMap = ft_CharToInt(nMap, cMap, nWidth);
	ft_scaffold(nMap, nWidth, nHeight);
}

