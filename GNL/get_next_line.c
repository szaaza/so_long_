/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:06:57 by sazanjan          #+#    #+#             */
/*   Updated: 2025/09/01 10:54:48 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_to_buffer(int fd, char *remainder)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	while (!remainder || !ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
			{
				free(remainder);
				return (NULL);
			}
			break ;
		}
		remainder = ft_append(remainder, buffer, bytes_read);
		if (!remainder)
			return (NULL);
	}
	return (remainder);
}

static char	*extract_line_from_buffer(char *remainder)
{
	size_t	line_len;
	char	*line;

	if (!remainder || !*remainder)
		return (NULL);
	line_len = 0;
	while (remainder[line_len] && remainder[line_len] != '\n')
		line_len++;
	if (remainder[line_len] == '\n')
		line_len++;
	line = ft_substr(remainder, 0, line_len);
	return (line);
}

static char	*clean_remainder(char *remainder)
{
	size_t	line_len;
	char	*new_remainder;
	size_t	remainder_len;

	if (!remainder)
		return (NULL);
	line_len = 0;
	while (remainder[line_len] && remainder[line_len] != '\n')
		line_len++;
	if (remainder[line_len] == '\n')
		line_len++;
	if (!remainder[line_len])
	{
		free(remainder);
		return (NULL);
	}
	remainder_len = ft_strlen(remainder) - line_len;
	new_remainder = ft_substr(remainder, line_len, remainder_len);
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_to_buffer(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line_from_buffer(remainder);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = clean_remainder(remainder);
	return (line);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

// example:
// -----------------
// bs = 4
// include "get_next_line.h"
// include <fcntl.h>

// remainder = include "get_next_line.h"
// in

// line = include "get_next_line.h"
// remainder = in
// ---------------------------------
// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;
//     int lines_to_read = 6;  
//     int i;

// fd = open("get_next_line.h", O_RDONLY);
// for (i = 1; i <= lines_to_read; i++)
// {
//     line = get_next_line(fd);
//     if (!line)
//     {
//         printf("Unexpected end of file at line %d\n", i);
//         break;
//     }
//     printf("Line %d: %s", i, line);
// 	free(line);  // Free each line properly
// }
// 	close(fd);
//     return (0);
// }
