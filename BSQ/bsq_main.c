#include "bsq.h"
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}



}

void	voir(t_var var)
{
	char c;
	write(1, "\n", 1);
	write(1, &var.plump, 1);
	write(1, "\n", 1);
	write(1, &var.obstacle, 1);
	write(1, "\n", 1);
	write(1, &var.blank, 1);
	c = var.len + 48;
	write(1, "\n", 1);
	write(1, &c, 1);
}

t_var	len_of_tab(t_var var, int i, char *str, char *nb)
{
	int tp;

	tp = i;
	i = 0;
	while (i <= tp)
	{
		nb[i] = str[i];
		i++;
	}
	nb[i] = '\0';
	var.len = ft_atoi(nb);
	return (var);
}

int		len_of_first_line(t_var var)
{
	int	i;
	char	tmp;

	tmp = 'a';
	i = 0;
	while (tmp != '\n' && tmp != '\0' && read(var.fd, &tmp, 1))
		i++;
	return (i);
}

t_var	first_line(t_var var)
{
	char	tmp;
	int		i;
	char	nb[17];
	char	str[20];

	i = 0;
	while (tmp != '\n' && read(var.fd, &tmp, 1))
	{
		str[i] = tmp;
		i++;
	}
	ft_putstr(str);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i--;
	var.plump = str[i--];;
	var.obstacle = str[i--];
	var.blank = str[i--];

	var = len_of_tab(var, i, str, nb);
	voir(var);
	return (var);
}

char **createtab(int nblin, int nbcol)
{
	char **tab = (char **)malloc(sizeof(char *)*nblin);
	char *tab2 = (char *)malloc(sizeof(char)*nbcol*nblin);
	int i;

	i = 0;
	while (i < nblin)
	{
		tab[i] = &tab2[i * nbcol];
		i++;
	}
	return (tab);
}

t_var	put_in_tab(t_var var)
{
	int		i;
	int		u;
	char	tmp;

	var = first_line(var);
	var.tab = createtab(var.len, len_of_first_line(var));
	
/*	i = 0;
	u = 0;
	while (read(var.fd, &tmp, 1) != 0)
	{
		if (tmp == '\n')
		{
			u++;
			i = 0;
		}
		else
		{
			var.tab[i][u] = tmp;
			i++;
		}
	}*/
}




int		main(int argc, char **argv)
{
	t_var var;

	var.curent_ac = 2;
	while (var.curent_ac <= argc)
	{
		var.fd = open(argv[var.curent_ac - 1], O_RDONLY);
		var = put_in_tab(var);
		close(var.fd);
		var.curent_ac++;
	}
	return (0);
}
