/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:18:08 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/03 14:42:13 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

/* 		GNL UTILS 		*/

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_readfd(int fd, char *buffle);
char	*cpyline(char *line);
char	*savenext(char *buffle);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_free_str(char *s);
int		test(char *s);


int ft_strcmp(char *str, char *str2);




#endif