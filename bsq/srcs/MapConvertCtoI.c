/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapConvertCtoI.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:58:30 by hana              #+#    #+#             */
/*   Updated: 2020/02/13 08:21:23 by hana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <stdio.h>

int		**ft_CharToInt(int **dst, char **src, int nWidth)
{
	int		nHeight;
	int 	i;
	int 	j;

	i = 0;
	nHeight = g_infoN;
	while (i < nHeight)
	{
		j = 0;
		while (j < nWidth)
		{
			if (src[i][j] == g_infoC[0])
			{
				dst[i][j] = 1;
			}
			else if (src[i][j] == g_infoC[1])
			{
				dst[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (dst);
}

void	ft_MakeinfoC(int j, char *src)
{
	g_infoC = (char *)malloc(sizeof(char) * j);
	g_infoC[2] = src[j - 1];
	g_infoC[1] = src[j - 2];
	g_infoC[0] = src[j - 3];	
}

int		ft_JoongBokPrintable(int j, int t, int x, char *buff)
{
	int		flag;

	flag = 1;
	while (buff[j] != '\n')
		j++;
	while (t < j)
	{
		x = 0;
		while (t + x + 1 < j)
		{
			if (buff[t] == buff[t + x + 1] || buff[x] < 32 || buff[x] == 127)
			{
				flag = 0;
				break;
			}
			x++;
		}
		t++;
	}
	return (flag);
}
