/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:26:05 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/12 19:21:17 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"

# ifndef SCALE
#  define SCALE 50
# endif

enum e_errors
{
	WALL_ERROR = 1,
	PLAYER_ERROR = 2,
	ALPHABET_ERROR = 3,
	RECTANGEL_ERROR = 4,
	EXIT_ERROR = 5,
	COIN_ERROR = 6,
	FILE_ERROR = 7,
	EXTENTION_ERROR = 8,
	MLX_ERROR = 9,
};

typedef struct s_flags
{
	int		wall;
	int		player;
	int		exit;
	int		coin;
}	t_flags;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_flags	flags;
	char	*map;
}	t_map;

typedef struct s_data
{
	size_t	x;
	size_t	y;
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
}	t_data;
//so_long
void	for_parsing(char *line, int error_code, t_map *m);
void	parsing(char *argv, t_map *m);

//parsing_utils
size_t	len_with_sl(const char *s);
char	*ft_strjoin_with_sl(char const *s1, char const *s2);
void	error(int error);
int		fd_map(char *path);
void	initialization(t_map *m, char *line);
//parsing
int		check_line(char *line, t_map *m);
void	check_error(int error_code, char *line, int wall);
void	check_error_after(t_map *m);
#endif