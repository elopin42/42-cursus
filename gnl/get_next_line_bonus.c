/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopin <elopin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:16:19 by elopin            #+#    #+#             */
/*   Updated: 2024/12/18 17:17:17 by elopin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line2(int fd, char **buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	i = ft_read(fd, &tmp);
	if (i < 0)
		return (free(*buffer), (*buffer) = NULL, i);
	(*buffer) = ft_strjoin((*buffer), tmp);
	free(tmp);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*str;
	char		*tmp;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!buffer[fd] || !check_nl(buffer[fd]))
	{
		i = ft_read(fd, &buffer[fd]);
		if (i < 0)
			return (free(buffer[fd]), buffer[fd] = NULL, NULL);
		while (i > 0 && !check_nl(buffer[fd]))
		{
			i = get_next_line2(fd, &buffer[fd]);
			if (i < 0)
				return (NULL);
		}
	}
	i = ft_write(&str, buffer[fd]);
	if (i <= 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	tmp = ft_substr(&buffer[fd], i, ft_strlen(buffer[fd]));
	return (free(buffer[fd]), buffer[fd] = tmp, str);
}

int	check_nl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int fd;
// 	char *str;

// 	str = NULL;
// 	fd = open("test.txt", O_RDONLY);
// 	int x = 1;
// 	while (x == 1)
// 	{
// 		str = get_next_line(fd);
// 		x++;
// 		printf("%s", str);
// 		free(str);
// 	}
// 	close(fd);
// 	fd = open("oui.txt", O_RDONLY);
// 	while(x < 5)
// 	{
// 		x++;
// 		str = get_next_line(fd);
// 		printf("2nd %s", str);
// 		free(str);
// 	}
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	int fd;
// 	char *str;

// 	str = NULL;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	close(fd);
// 	return (0);
// }