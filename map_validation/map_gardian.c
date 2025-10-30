#include "so_long.h"

static void	check_rectangular(t_game *game)
{
	int	expected_len;

	expected_len = ft_strlen(game->map.grid[0]);
	check_row_length(game->map.grid, expected_len);
}


static void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			validate_char(game->map.grid[i][j]);
			j++;
		}
		i++;
	}
}

static void	locate_game_entities(t_game *game)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	p_count = 0;
	e_count = 0;
	game->map.collectibles = 0;
	i = -1;
	while (game->map.grid[++i])
	{
		j = -1;
		while (game->map.grid[i][++j])
			count_map_entities(game, i, j, &p_count, &e_count);
	}
	if (p_count != 1)
		error_exit("Map must have exactly one player");
	if (e_count != 1)
		error_exit("Map must have exactly one exit");
	if (game->map.collectibles < 1)
		error_exit("Map must have at least one collectible");
}

int	validate_map(t_game *game)
{
	game->map.width = ft_strlen(game->map.grid[0]);
	game->map.height = 0;
	while (game->map.grid[game->map.height])
		game->map.height++;

	check_rectangular(game);
	check_characters(game);
	locate_game_entities(game);
	// if (!check_path(game))
	// 	error_exit("No valid path in map");

	return (1);
}

