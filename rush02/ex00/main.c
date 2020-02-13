/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:57:09 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 18:07:18 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

#define BUF_SIZE 10000

void			ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			rm_sp(char *s, int j)
{
	while (s[j + 1])
	{
		s[j] = s[j + 1];
		j++;
	}
	s[j] = '\0';
}

void			remove_space(t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].len)
	{
		j = 0;
		while (dict[i].str[j])
		{
			while (dict[i].str[j] == ' ' && dict[i].str[j + 1] == ' ')
				rm_sp(dict[i].str, j);
			j++;
		}
		i++;
	}
}

int				main(int ac, char **av)
{
	t_dict	*dict;
	char	*s;

	s = ft_atoi(av[ac - 1]);
	dict = parse("numbers.dict");
	if (ac != 2 || !s || !dict || !ft_chk_param(ac, s))
	{
		ft_putstr("Error\n");
		return (0);
	}
	remove_space(dict);
	sort_dict(dict);
	if (!ft_strcmp(s, "0"))
		ft_putstr(dict[0].str);
	else if (!s)
		ft_putstr("Error");
	else
		print_number(s, ft_strlen(s), dict);
	ft_putstr("\n");
	ft_clean_memory(&dict);
	return (0);
}
