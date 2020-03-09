/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:16:42 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/05 12:58:40 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# define BUFF 600

int		g_c;
int		g_h;
int		g_i;
int		g_n;
int		g_m;
int		g_sh;
int		g_size;
char	g_f;
int		g_x;
char	**g_str;
char	***g_mas;
char	**g_map;

int		ft_validator(int fd);
int		ft_field(char *s);
int		ft_check(char *s);
int		sup_ft_field(char *s);
void	sup_ft_check(void);
void	ft_sdvig_vlevo(void);
void	ft_cut_right(void);
void	ft_cut(void);
void	ft_fillit(void);
void	hash_to(void);
void	ft_mas(void);
void	ft_map(void);
int		ft_ylen(int k);
int		ft_hlen();
void	solve(void);
void	ft_start_map(void);
int		ft_valid_tetr(char *fd);
int		ft_valid_map(char *fd);

#endif
