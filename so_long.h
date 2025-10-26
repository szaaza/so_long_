/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:17:03 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/26 16:52:33 by sazanjan         ###   ########.fr       */
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

//updat the functions which is already in the so_long.h file

void	error_exit(char *msg);

//get_next_line functions
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_append(char *s1, char *s2, size_t len);


#endif // SO_LONG_H