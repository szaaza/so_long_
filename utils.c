/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:52:04 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/27 12:20:51 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	result;
	
	i = 0;
	result = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		result = (unsigned char)s1[i] -(unsigned char) s2[i];
		if (result == 0)
		i++;
		else
			return (result);
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		return (0);
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	index;
	
	if (!s)
	return ;
	index = 0;
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
// ******************************************************************************
// Ucheck function for input file check
// void	ucheck(t_game *game)
// {
// 	int	i = 0;

// 	printf(">>> Entered ucheck\n"); // Debug print

// 	if (!game->map.grid)
// 	{
// 		ft_putstr_fd("Map not loaded!\n", 1);
// 		return;
// 	}

// 	ft_putstr_fd("=== MAP CHECK ===\n", 1);
// 	while (game->map.grid[i])
// 	{
// 		ft_putstr_fd(game->map.grid[i], 1);
// 		ft_putstr_fd("\n", 1);
// 		i++;
// 	}
// 	ft_putstr_fd("=================\n", 1);
// }
// ******************************************************************************
//ucheck for map evaluation
void	ucheck(t_game *game)
{
	int	i;

	if (!game->map.grid)
	{
		ft_putstr_fd("❌ Map not loaded!\n", 1);
		return;
	}

	ft_putstr_fd("🔍 Checking map validity...\n", 1);

	// Print basic map info
	printf("Map width: %d\n", game->map.width);
	printf("Map height: %d\n", game->map.height);
	printf("Collectibles: %d\n", game->map.collectibles);
	printf("Player: (%d, %d)\n", game->map.player_x, game->map.player_y);
	printf("Exit: (%d, %d)\n", game->map.exit_x, game->map.exit_y);

	// Print the map grid
	ft_putstr_fd("=== MAP GRID ===\n", 1);
	i = 0;
	while (game->map.grid[i])
	{
		ft_putstr_fd(game->map.grid[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("=================\n", 1);

	// Run validation
	if (validate_map(game))
		ft_putstr_fd("✅ Map is valid!\n", 1);
	else
		ft_putstr_fd("❌ Map is invalid!\n", 1);
}
