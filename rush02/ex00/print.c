/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:49:48 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 18:06:54 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_dict(char *s, t_dict dict)
{
	if (s[0] != '0')
	{
		ft_putstr(dict.str);
		if (*(s + 1))
			ft_putstr(" ");
	}
}

void	print_number(char *s, int len, t_dict *dict)
{
	t_dict	temp;

	if (!len)
		return ;
	temp = find_dict(s, len, len, dict);
	if (temp.len)
	{
		print_dict(s, temp);
		return ;
	}
	temp = find_closest(s, len, dict);
	if (temp.len == 2)
	{
		print_dict(s, temp);
		print_number(s + 1, len - 1, dict);
		return ;
	}
	temp = find_power(len, dict);
	print_number(s, len - temp.len + 1, dict);
	print_dict(s, temp);
	print_number(s + (len - temp.len + 1), temp.len - 1, dict);
}
