/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:49:04 by hana              #+#    #+#             */
/*   Updated: 2020/02/13 08:21:43 by hana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

void	ft_scaffold(int **M, int nWidth, int nHeight)
{
	int i;
	int j;
	int **S;

	S = (int **)malloc(sizeof(int *) * nHeight);
	i = 0;
	while (i < nHeight)
	{
		S[i] = (int *)malloc(sizeof(int) * nWidth + 1);
		i++;
	}
	i = 0;
	while (i < nHeight)
	{
		S[i][0] = M[i][0];
		i++;
	}
	j = 1;
	while (j < nWidth)
	{
		S[0][j] = M[0][j];
		j++;
	}
	ft_construct(M, S, nWidth, nHeight);
}

void	ft_construct(int **M, int **S, int nWidth, int nHeight)
{
	int i;
	int j;

	i = 1;
	while (i < nHeight)
	{
		j = 1;
		while (j < nWidth)
		{
			if (M[i][j] == 1)
			{
				S[i][j] = S[i][j - 1];
				if (S[i][j] > S[i - 1][j])
					S[i][j] = S[i - 1][j];
				if (S[i][j] > S[i - 1][j - 1])
					S[i][j] = S[i - 1][j - 1];
				S[i][j] += 1;
			}
			else
				S[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_find_max(M, S, 0, 0, nWidth, 0);
}

void	ft_find_max(int **M, int **S, int i, int j, int nWidth, int max_of_s)
{
	int max_i;
	int max_j;

	max_i = 0;
	max_j = 0;
	while (i < g_infoN)
	{
		j = 0;
		while (j < nWidth)
		{
			if (max_of_s <=  S[i][j])
			{
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}
	ft_pr(M, max_of_s, max_i, max_j, nWidth);
}

void	ft_pr(int **M, int max_of_s, int max_i, int max_j, int W)
{
	int i;
	int j;
	
	i = 0;
	while (i < g_infoN)
	{
		j = 0;
		while (j < W)
		{
			if (i <= max_i && i > max_i - max_of_s && j <= max_j && j > max_j - max_of_s)
				write(1, &g_infoC[2], 1);
			else
			{
				if (M[i][j] == 1)
					write(1, &g_infoC[0], 1);
				else
					write(1, &g_infoC[1], 1);
			}
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
