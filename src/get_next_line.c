/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:46:02 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/08 16:17:59 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_readfd(int fd, char *buffle)
{
	int		r;
	char	*save;

	save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		return (0);
	r = 1;
	while (!test(buffle) && r > 0)
	{
		r = read(fd, save, BUFFER_SIZE);
		if (r < 0)
		{
			free(save);
			return (0);
		}
		save[r] = 0;
		buffle = ft_strjoin(buffle, save);
	}
	free(save);
	return (buffle);
}

char	*cpyline(char *line)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (line == NULL)
		return (0);
	if (line[0] == 0)
		return (NULL);
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free(str), NULL);
	while (i < len)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*savenext(char *buffle)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	if (!buffle)
		return (NULL);
	while (buffle[i] != '\0' && buffle[i] != '\n')
		i++;
	if (buffle[i] == '\n')
		i++;
	if (ft_strlen(buffle) == 0)
		return (free(buffle), NULL);
	new = malloc(sizeof(char) * (ft_strlen(buffle) - i + 1));
	if (!new)
		return (free(buffle), free(new), NULL);
	j = 0;
	while (buffle[i])
		new[j++] = buffle[i++];
	new[j] = '\0';
	return (free(buffle), new);
}

char	*get_next_line(int fd, int flag)
{
	char		*line;
	static char	*buffle;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (flag == 1)
		return (free(buffle), NULL);
	buffle = ft_readfd(fd, buffle);
	if (!buffle)
		return (free(buffle), NULL);
	line = cpyline(buffle);
	buffle = savenext(buffle);
	return (line);
}
/* 
 
#include <stdio.h>

int main()
{
	int fd;
	char *res;

    int    i = 1;

	fd = open("lol.txt", O_RDONLY);

    res = get_next_line(12);

    while (res)
    {
		printf("%s", res);
        free(res);
        res = get_next_line(12);

    }

    close(fd);
    return (0);
} */