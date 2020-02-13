/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:51:35 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 17:11:53 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	ft_clean_memory(t_dict **dict)
{
	int i;

	i = 0;
	while ((*dict)[i].len)
	{
		free((*dict)[i].str);
		free((*dict)[i].number);
		i++;
	}
	free(*dict);
}
