/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:52:53 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 17:24:16 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_chk_param(int ac, char *str)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!str[0])
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
