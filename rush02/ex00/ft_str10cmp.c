/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str10cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:53:47 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 17:18:58 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

int		ft_str10cmp(char *s1, char *s2, int n)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = 10 * res + ft_abs((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (res);
}
