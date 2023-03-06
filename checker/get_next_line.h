/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rencarna <rencarna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:07:33 by ruru              #+#    #+#             */
/*   Updated: 2023/03/06 16:36:25 by rencarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>	
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd, int flag);
char	*ft_readfd(int fd, char *buffle);
char	*cpyline(char *line);
char	*savenext(char *buffle);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_free(char *s);
int		test(char *s);

#endif