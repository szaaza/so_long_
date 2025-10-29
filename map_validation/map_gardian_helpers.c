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