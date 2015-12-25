/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <zzeller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 12:59:16 by zzeller           #+#    #+#             */
/*   Updated: 2015/10/18 00:31:17 by zzeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		nb;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] == ' ') || (str[i] == '	'))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '+')
			sign *= -1;
		sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] > '9') || (str[i] < '0'))
			return (nb * sign);
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
