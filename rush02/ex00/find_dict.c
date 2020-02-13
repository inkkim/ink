/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:48:07 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 16:59:39 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

t_dict	find_dict(char *s, int size, int len, t_dict *dict)
{
	int i;

	i = 0;
	while (dict[i].len)
	{
		if (size == dict[i].len && !ft_strncmp(dict[i].number, s, len))
			return (dict[i]);
		i++;
	}
	return (dict[i]);
}

t_dict	find_power(int len, t_dict *dict)
{
	int i_res;
	int i;

	i = 0;
	i_res = 0;
	while (dict[i].len)
	{
		if (len >= dict[i].len)
			if (dict[i_res].len < dict[i].len)
				i_res = 1;
		i++;
	}
	return (dict[i_res]);
}

t_dict	find_closest(char *s, int len, t_dict *dict)
{
	int		i;
	int		i_res;
	int		find;
	int		diff;

	diff = 256;
	i = 0;
	i_res = 0;
	find = 0;
	while (dict[i + 1].len)
	{
		if (len == dict[i].len &&
			ft_str10cmp(s, dict[i].number, len) <
			ft_str10cmp(s, dict[i_res].number, len))
		{
			i_res = 1;
			find = 1;
		}
		i++;
	}
	if (find)
		return (dict[i_res]);
	return (dict[i]);
}
