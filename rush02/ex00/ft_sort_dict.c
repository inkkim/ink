/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:49:05 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 18:01:40 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	sort_len(t_dict *dict)
{
	int		i;
	t_dict	temp;
	int		sort;

	sort = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (dict[i + 1].len)
		{
			if (dict[i].len > dict[i + 1].len)
			{
				temp = dict[i];
				dict[i] = dict[i + 1];
				dict[i + 1] = temp;
				sort = 0;
			}
			i++;
		}
	}
}

void	sort_ascii(t_dict *dict)
{
	int		i;
	int		sort;
	t_dict	temp;

	sort = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (dict[i + 1].len)
		{
			if (dict[i].len == dict[i + 1].len &&
					ft_strcmp(dict[i].number, dict[i + 1].number) > 0)
			{
				temp = dict[i];
				dict[i] = dict[i + 1];
				dict[i + 1] = temp;
				sort = 0;
			}
			i++;
		}
	}
}

void	sort_dict(t_dict *dict)
{
	sort_len(dict);
	sort_ascii(dict);
}
