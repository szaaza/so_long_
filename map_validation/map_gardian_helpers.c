#include "so_long.h"

void	check_row_length(char **grid, int expected_len)
{
	int	len;
	int	i;

	i = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len == 0)
			error_exit("Empty line in map");
		if (len != expected_len)
			error_exit("Map is not rectangular");
		i++;
	}
}

void	validate_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		error_exit("Invalid character in map");
}
void	count_map_entities(t_game *game, int i, int j, int *p_count, int *e_count)
{
	char c = game->map.grid[i][j];

	if (c == 'P')
	{
		game->map.player_x = j;
		game->map.player_y = i;
		(*p_count)++;
	}
	else if (c == 'E')
	{
		game->map.exit_x = j;
		game->map.exit_y = i;
		(*e_count)++;
	}
	else if (c == 'C')
		game->map.collectibles++;
}

#include "so_long.h"

void	check_horizontal_walls(t_game *game)
{
	int	i;
	int	width;
	int	height;

	width = game->map.width;
	height = game->map.height;
	i = 0;
	while (i < width)
	{
		if (game->map.grid[0][i] != '1'
			|| game->map.grid[height - 1][i] != '1')
			error_exit("Map must be surrounded by walls");
		i++;
	}
}

void	check_vertical_walls(t_game *game)
{
	int	i;
	int	width;
	int	height;

	width = game->map.width;
	height = game->map.height;
	i = 0;
	while (i < height)
	{
		if (game->map.grid[i][0] != '1'
			|| game->map.grid[i][width - 1] != '1')
			error_exit("Map must be surrounded by walls");
		i++;
	}
}