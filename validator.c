/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:05:40 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/05 12:59:03 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sup_ft_field(char *s)
{
	while (s[g_m] != '\0')
	{
		if ((s[g_m] == '.' || s[g_m] == '#') && g_i < 4 && g_h < 4)
		{
			g_m++;
			g_i++;
		}
		else if (s[g_m] == '\n' && g_i == 4 && s[g_m] != '\0')
		{
			g_i = 0;
			g_m++;
			g_h++;
			if (s[g_m] == '\n' && g_h == 4)
			{
				g_m++;
				if (s[g_m] == '.' || s[g_m] == '#')
					g_h = 0;
				else
					return (0);
			}
		}
		else
			return (0);
	}
	return (1);
}

void	sup_ft_check(void)
{
	while (g_str[g_h][g_i] == '#')
	{
		g_c++;
		if (g_str[g_h][g_i] == g_str[g_h][g_i + 1])
			g_sh++;
		if (g_i > 0 && g_str[g_h][g_i] == g_str[g_h][g_i - 1])
			g_sh++;
		if (g_i < 15 && g_str[g_h][g_i] == g_str[g_h][g_i + 5])
			g_sh++;
		if (g_i > 4 && g_str[g_h][g_i] == g_str[g_h][g_i - 5])
			g_sh++;
		g_i++;
	}
}

int		ft_check(char *s)
{
	g_i = 0;
	g_h = 0;
	g_str = ft_strsplit(s, '*');
	while (g_str[g_h])
	{
		if (g_str[g_h][g_i] == '#')
			sup_ft_check();
		if (g_str[g_h][g_i] == '\0')
		{
			if ((g_c == 4 && g_sh == 6) || (g_c == 4 && g_sh == 8))
			{
				g_h++;
				g_i = 0;
				g_sh = 0;
				g_c = 0;
			}
			else
				return (0);
		}
		else
			g_i++;
	}
	return (1);
}

int		ft_field(char *s)
{
	g_m = 0;
	g_i = 0;
	g_h = 0;
	g_sh = 0;
	g_c = 0;
	g_n = 0;
	if (sup_ft_field(s))
	{
		if (g_h == 4)
			return (1);
	}
	return (0);
}

int		ft_validator(int fd)
{
	char s[BUFF + 1];

	read(fd, s, BUFF);
	if (s[0] == '\0')
		return (0);
	if (ft_field(s) == 1)
	{
		g_h = 0;
		while (s[g_i])
		{
			if (s[g_i] == '\n')
				g_n++;
			if (g_n == 5)
			{
				g_h++;
				s[g_i] = '*';
				g_n = 0;
			}
			g_i++;
		}
		g_size = g_h + 1;
		if (g_h < 26 && ft_check(s) == 1)
			return (1);
	}
	return (0);
}
