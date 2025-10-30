#include "so_long.h"

void	check_row_length(char **grid, int expected_len)
{
	int	len;
	int	i;

	i = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
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