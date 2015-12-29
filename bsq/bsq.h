/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeller <zzeller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 09:48:22 by zzeller           #+#    #+#             */
/*   Updated: 2015/12/29 14:25:22 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_char
{
	char	obstacle;
	char	blank;
	char	plump;
	int		fd;
	int		buffer;
	int		i;
	int		j;
	int		k;
}					t_char;
typedef struct		s_var
{
	int		curent_ac;
	int		fd;
	char	**tab;
	char	*line;
	char	obstacle;
	char	blank;
	char	plump;
	int		len;
	char	**agv;
	int		i;
}					t_var;

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
t_char	ft_first_line();
int		ft_strlen_compare(t_char sub, char *arg, char *tmp);
int		ft_strcmp(char *s1, char *s2);
int		ft_valid_file();
char			**ft_strsplit(char const *s, char c);
#endif
