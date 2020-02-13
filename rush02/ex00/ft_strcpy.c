/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:54:54 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 18:06:27 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src, char *stop)
{
	int i;

	i = 0;
	while (src[i] != stop[0] && src[i] != stop[1])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src, char *sep)
{
	char	*tab;
	int		len;

	len = 0;
	while (src[len] != sep[0] && src[len] != sep[1])
		len++;
	tab = (char*)malloc(sizeof(*src) * (len + 1));
	if (tab != 0)
	{
		ft_strcpy(tab, src, sep);
		return (tab);
	}
	return (0);
}
