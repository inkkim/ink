/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:52:03 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 17:12:27 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

char	*skip_zero(char *str)
{
	unsigned int	i;
	unsigned int	j;

	if (!(*str))
		return (str);
	i = 0;
	while (str[i] == '0')
		i++;
	j = 0;
	if (i == ft_strlen(str))
	{
		str = "0";
		return (str);
	}
	while (j + i <= ft_strlen(str))
	{
		str[j] = str[j + i];
		j++;
	}
	return (str);
}

char	*ft_atoi(char *str)
{
	int		len;
	int		i;
	int		j;
	char	sep;

	i = 0;
	len = ft_strlen(str);
	if (!(*str) || !(len > 4 && (str[len - 4] == ' ' || str[len - 4] == ',')))
		return (skip_zero(str));
	sep = str[len - 4];
	while (str[len - ++i])
	{
		if (!(i % 4))
		{
			if (str[len - i] != sep)
			{
				ft_putstr("Error\n");
				return (0);
			}
			j = len - i - 1;
			while (str[++j])
				str[j] = str[j + 1];
		}
	}
	return (skip_zero(str));
}
