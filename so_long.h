/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:17:03 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/27 12:21:37 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//make .h file for so_long project
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stddef.h>
# include <stdlib.h> //for malloc, free, exit
# include <unistd.h> //for read, write, close
# include <fcntl.h>  //for open
# include <stdio.h>  //for printf, perror
// # include <mlx.h>    //for mlx functions

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
#endif // BUFFER_SIZE

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;


typedef struct s_game
{
    t_map	map;
}	t_game;

//utils functions
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	error_exit(char *msg);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ucheck(t_game *game);


//get_next_line functions
char	*get_next_line(int fd);
// size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_append(char *s1, char *s2, size_t len);

//map functions
char	**load_map_from_file(const char *path);

#endif // SO_LONG_H