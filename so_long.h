/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:17:03 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/25 21:58:52 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//make .h file for so_long project
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> //for malloc, free, exit
# include <unistd.h> //for read, write, close
# include <fcntl.h>  //for open
# include <stdio.h>  //for printf, perror
// # include <mlx.h>    //for mlx functions

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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


void	error_exit(char *msg);


#endif // SO_LONG_H