/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:25 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/13 01:45:37 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		stash_len(char *str);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int fre);
void	*ft_free_stuff(void *p1, void *p2, void *p3);

char	*get_next_line(int fd);

#endif
