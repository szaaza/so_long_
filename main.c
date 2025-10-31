/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:52:28 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/26 19:23:00 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len <= 4)
		error_exit("Invalid file name");
	if (ft_strncmp(&file[len - 4], ".ber", 4) != 0)
		error_exit("Map file must have .ber extension");
}

static void	begin_game(t_game *game, char *file)
{
	check_file(file);
	game->map.grid =load_map_from_file(file);
	validate_map(game);
	ucheck(game);

}
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map.ber>");
	begin_game(&game, argv[1]);
	return (0);
}

