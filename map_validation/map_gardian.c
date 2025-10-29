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

int	validate_map(t_game *game)
{
	game->map.width = ft_strlen(game->map.grid[0]);
	game->map.height = 0;
	while (game->map.grid[game->map.height])
		game->map.height++;

	check_rectangular(game);
	check_characters(game);


	return (1);
}