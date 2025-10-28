/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:57:51 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/26 19:35:24 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_file(const char *path)
{
	int	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open file");
	return (fd);
}
static int	get_file_line_count(const char *path)
{
	int		fd;
	int		lines;
	char	*buffer;

	fd = open_file(path);
	lines = 0;
	while ((buffer = get_next_line(fd)) != NULL)
	{
		lines++;
		free(buffer);
	}
	close(fd);
	return (lines);
}

static char	**allocate_map_array(int line_count)
{
	char **map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		error_exit("Memory allocation failed for map");
	return (map);
}
static char	*make_a_(char *str)
{
	int	num;

	if (!str)
		return (NULL);
	num = ft_strlen(str);
	if (num > 0 && str[num - 1] == '\n')
		str[num - 1] = '\0';
	return (str);
}

char	**load_map_from_file(const char *path)
{
	char	**map;
	int		fd;
	int		Mat;
	int		line_numbers;
	char	*b;

	line_numbers = get_file_line_count(path);
	if (line_numbers == 0)
		error_exit("Map file has no input! fill it...");

	map = allocate_map_array(line_numbers);
	fd = open_file(path);
	Mat = 0;

	while (Mat < line_numbers)
	{
		b = get_next_line(fd);
		map[Mat] = make_a_(b);
		Mat++;
	}
	map[Mat] = NULL;
	close(fd);
	return (map);
}
