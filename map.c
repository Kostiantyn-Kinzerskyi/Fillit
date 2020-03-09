/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:00:54 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/05 12:59:26 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(void)
{
	int i;

	i = 0;
	while (g_map[i])
	{
		free(g_map[i]);
		i++;
	}
	free(g_map);
}

void	ft_map(void)
{
	g_n = 0;
	g_m = 0;
	g_x = g_size;
	ft_free_map();
	g_map = (char**)malloc(sizeof(char*) * (g_x + 1));
	while (g_n < g_x)
	{
		g_map[g_n] = (char*)malloc(sizeof(char) * (g_x + 1));
		g_m = 0;
		while (g_m < g_x)
		{
			g_map[g_n][g_m] = '.';
			g_m++;
		}
		g_map[g_n][g_m] = '\0';
		g_n++;
	}
	g_map[g_n] = 0;
	g_n = 0;
	g_m = 0;
}

void	ft_start_map(void)
{
	int l;

	g_n = 0;
	g_m = 0;
	g_x = 0;
	l = ft_sqrt(g_size * 4);
	g_map = (char**)malloc(sizeof(char*) * (l + 1));
	while (g_n < l)
	{
		g_map[g_n] = (char*)malloc(sizeof(char) * (l + 1));
		g_m = 0;
		while (g_m < l)
		{
			g_map[g_n][g_m] = '.';
			g_m++;
		}
		g_map[g_n][g_m] = '\0';
		g_n++;
	}
	g_map[g_n] = 0;
	g_n = 0;
	g_m = 0;
}

int		ft_hlen(void)
{
	int	i;

	i = 0;
	while (g_map[i])
		i++;
	return (i);
}

int		ft_ylen(int k)
{
	int	i;

	i = 0;
	while (g_mas[k][i])
		i++;
	return (i);
}
