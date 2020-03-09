/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:06:12 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/05 13:04:12 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printmap(void)
{
	int i;

	i = 0;
	while (g_map[i])
		ft_putendl(g_map[i++]);
}

int		main(int argc, char **argv)
{
	int fd;
	int t;

	t = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetramino_file");
		return (0);
	}
	if (argc > 0)
	{
		fd = open(argv[1], O_RDONLY);
		t = ft_validator(fd);
	}
	if (t == 1)
	{
		hash_to();
		ft_start_map();
		solve();
		printmap();
	}
	if (t == 0)
		ft_putendl("error");
	return (0);
}
