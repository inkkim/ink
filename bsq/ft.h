/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:25:38 by hana              #+#    #+#             */
/*   Updated: 2020/02/13 07:40:44 by inkkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#define FileInfoNumber 5
#define MAX_COLS 255
#define	SIZE 255

int		g_infoN;
char	*g_infoC;
char 	**g_cMap;

char	*ft_SetMaptemp(int i, char *buff, char *cMaptemp);
void	ft_SetMapInfo(int i, int j, int k, int t, int x, char *buff);
char	*ft_Setbuff(char *argv);
int		ft_ReadAndBuff(int argc, char **argv);
int		ft_SetnWidth(int i, char *cMaptemp);
char	**ft_SetMap(char **cMap, char *cMaptemp, int nHeight, int nWidth);
int		ft_CheckMapChar(char **Map, int nWidth, int nHeight);
int		ft_CheckMapWidth(int nHeight, int nWidth, char **cMap);
void	ft_SetCharMap(char *cMaptemp, int i);
void	ft_scaffold(int **M, int nWidth, int nHeight);
void	ft_construct(int **M, int **S, int nWidth, int nHeight);
void	ft_find_max(int **M, int **S, int i, int j, int nWidth, int max_of_s);
void	ft_pr(int **M, int max_of_s, int max_i, int max_j, int W);
int		**ft_CharToInt(int **dst, char **src, int nWidth);
void	ft_MakeinfoC(int j, char *src);
int		ft_JoongBokPrintable(int j, int t, int x, char *buff);

#endif
