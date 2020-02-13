/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhan <suhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:58:43 by suhan             #+#    #+#             */
/*   Updated: 2020/02/09 17:25:36 by suhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_dict
{
	char	*number;
	char	*str;
	int		len;
}				t_dict;

char			*ft_strcat(char *s1, char *s2);
unsigned int	ft_strlen(char *s);
void			ft_putstr(char *s);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
t_dict			find_dict(char *s, int size, int len, t_dict *dict);
t_dict			find_power(int len, t_dict *dict);
t_dict			find_closest(char *s, int len, t_dict *dict);
void			sort_dict(t_dict *dict);
void			print_number(char *s, int len, t_dict *dict);
t_dict			*parse(char *s);
char			*ft_strdup(char *src, char *sep);
int				ft_strcmp(char *s1, char *s2);
int				ft_str10cmp(char *s1, char *s2, int n);
int				ft_abs(int a);
int				ft_chk_param(int ac, char *str);
char			*ft_atoi(char *str);
void			ft_clean_memory(t_dict **dict);

#endif
