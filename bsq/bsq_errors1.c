/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_errors1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <zzeller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 09:44:23 by zzeller           #+#    #+#             */
/*   Updated: 2015/12/18 11:55:20 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_char	ft_first_line(char *arg, char *tmp, t_char sub)
{
	sub.fd = open(arg, O_RDONLY);
	sub.i = 0;
	while (tmp[sub.i] != '\n')
	{
		tmp[sub.i] = read(sub.fd, &sub.buffer, 1);
		sub.i++;
	}
	if (sub.fd >= 0 && sub.i == 3)
	{
		sub.obstacle = read(sub.fd, &sub.buffer, 1);
		sub.blank = read(sub.fd, &sub.buffer, 1);
		sub.plump = read(sub.fd, &sub.buffer, 1);
		ft_strlen_compare(sub, arg, tmp);
	}
	else
		ft_putstr_error("map error\n");
	close(sub.fd);
	return (sub);
}

int		ft_strlen_compare(t_char sub, char *arg, char *tmp)
{
	sub.i = 0;
	sub.j = 0;
	while (tmp[sub.i] != '\n')
	{
		tmp[sub.i] = read(sub.fd, &sub.buffer, 1);
		sub.i++;
	}
	while (read(sub.fd, &sub.buffer, 1) != 0 && sub.k != 0)
	{
		while (tmp[sub.j] != '\n')
			sub.j++;
		if (sub.i == sub.j)
			sub.k = 1;
		else
			sub.k = 0;
	}
	if (sub.k == 0)
	{
		ft_putstr_error("map error\n");
		return (0);
	}
	else
		return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_valid_file(char *arg, char *tmp, t_char sub)
{
	ft_first_line(arg, tmp, sub);
}
