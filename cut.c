/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:16:08 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/05 12:58:34 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	hash_to(void)
{
	char	sy;

	sy = 'A';
	ft_mas();
	while (g_str[g_h])
	{
		if (g_str[g_h][g_i] == '#')
			g_str[g_h][g_i] = sy;
		g_i++;
		if (g_str[g_h][g_i] == '\0')
		{
			g_h++;
			g_i = 0;
			sy++;
		}
	}
	g_mas = (char***)malloc(sizeof(char***) * (g_h + 1));
	g_h = 0;
	while (g_str[g_h])
	{
		g_mas[g_h] = ft_strsplit(g_str[g_h], '\n');
		g_h++;
	}
	g_mas[g_h] = 0;
}

void	ft_sdvig_vlevo(void)
{
	g_i = 0;
	while (g_i < g_sh)
	{
		if (g_str[g_h][g_i] == '#')
			break ;
		else if (g_str[g_h][g_i + 5] == '\0')
		{
			g_i = 0;
			while (g_str[g_h][g_i])
			{
				if (g_str[g_h][g_i] == '\n')
					g_i++;
				if (g_i < g_sh && g_str[g_h][g_i + 1] != '\n')
				{
					g_f = g_str[g_h][g_i];
					g_str[g_h][g_i] = g_str[g_h][g_i + 1];
					g_str[g_h][g_i + 1] = g_f;
				}
				g_i++;
			}
			g_i = 0;
		}
		else
			g_i += 5;
	}
}

void	ft_cut_right(void)
{
	while (g_str[g_h][g_i] != '#')
		g_i++;
	while (g_str[g_h][g_i] == '#')
	{
		g_i++;
		g_sh++;
		if (g_str[g_h][g_i] == '\n')
			while (g_str[g_h][g_i] != '#' && g_sh < 4)
				g_i++;
	}
	while (g_str[g_h][g_i + 1] != '\0' && g_sh < 4)
	{
		g_f = g_str[g_h][g_i];
		g_str[g_h][g_i] = g_str[g_h][g_i + 1];
		g_str[g_h][g_i + 1] = g_f;
		g_i++;
	}
	if (g_sh >= 4)
		g_str[g_h][g_i] = '\0';
	if (g_str[g_h][g_i + 1] == '\0' && g_sh < 4)
	{
		g_i = 0;
		g_sh = 0;
	}
}

void	ft_cut(void)
{
	g_sh = 0;
	while (g_str[g_h][g_i])
		g_i++;
	while (g_str[g_h][g_i] != '#')
		g_i--;
	while (g_str[g_h][g_i] != '\n')
		g_i++;
	g_str[g_h][g_i + 1] = '\0';
	g_sh = g_i + 1;
	ft_sdvig_vlevo();
	g_i = 0;
	g_sh = 0;
	while (g_sh < 4)
		ft_cut_right();
	g_h++;
	g_i = 0;
}

void	ft_mas(void)
{
	g_i = 0;
	g_h = 0;
	while (g_str[g_h])
	{
		while (g_str[g_h][g_i] != '\n' && g_str[g_h][g_i] != '#')
			g_i++;
		if (g_str[g_h][g_i] == '\n')
		{
			g_i++;
			while (g_str[g_h][g_i])
			{
				g_str[g_h][g_i - 5] = g_str[g_h][g_i];
				g_i++;
			}
			g_i -= 5;
			g_str[g_h][g_i] = '\0';
			g_i = 0;
		}
		if (g_str[g_h][g_i] == '#')
			ft_cut();
	}
	g_i = 0;
	g_h = 0;
}
