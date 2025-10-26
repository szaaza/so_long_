/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:57:51 by sazanjan          #+#    #+#             */
/*   Updated: 2025/10/26 18:30:03 by sazanjan         ###   ########.fr       */
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

char	**load_map_from_file(const char *path)
{
	char	**map;
	int		fd;
	int		Mat;
	int		line_numbers;
	char	*b1;

	line_numbers = get_file_line_count(path);
	if (line_numbers == 0)
		error_exit("Map file has no input! fill it...");

	return (map);
}