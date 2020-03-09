/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:15:43 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/05 12:59:15 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_put(int h, int i, int j)
{
	int x;
	int z;
	int k;

	k = j;
	x = 0;
	while (g_mas[h][x])
	{
		z = 0;
		j = k;
		while (g_mas[h][x][z])
		{
			if (g_mas[h][x][z] != '.')
				if (g_map[i][j] != '.')
					return (0);
			z++;
			j++;
		}
		i++;
		x++;
	}
	return (1);
}

int		put(int h, int i, int j)
{
	int y;
	int z;
	int	k;

	k = j;
	y = 0;
	if (!try_put(h, i, j))
		return (0);
	while (g_mas[h][y])
	{
		z = 0;
		j = k;
		while (g_mas[h][y][z])
		{
			if (g_mas[h][y][z] != '.')
				g_map[i][j] = g_mas[h][y][z];
			j++;
			z++;
		}
		i++;
		y++;
	}
	return (1);
}

void	del_tetr(int k)
{
	int		i;
	int		h;
	int		b;

	i = 0;
	b = 0;
	while (g_map[i])
	{
		h = 0;
		while (g_map[i][h])
		{
			if (g_map[i][h] == k + 'A')
			{
				g_map[i][h] = '.';
				b++;
			}
			if (b == 4)
				return ;
			h++;
		}
		i++;
	}
}

int		ft_puttet(int k)
{
	int	i;
	int	b;

	if (!g_mas[k])
		return (1);
	i = 0;
	g_c = (int)ft_strlen(g_mas[k][0]);
	while (i + ft_ylen(k) <= g_size)
	{
		b = 0;
		while (b + g_c <= g_size)
		{
			if (put(k, i, b))
			{
				if (ft_puttet(k + 1))
					return (1);
				else
					del_tetr(k);
			}
			b++;
		}
		i++;
	}
	return (0);
}

void	solve(void)
{
	g_size = ft_hlen();
	while (!ft_puttet(0))
	{
		g_size++;
		ft_map();
	}
}
