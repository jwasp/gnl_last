/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:17:55 by jwasp             #+#    #+#             */
/*   Updated: 2020/12/22 04:33:30 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE (4*1024)
#endif
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
 size_t	ft_strlen(const char *str);
 char	*ft_strjoin(char const *s1, char const *s2);
 char	*ft_strdup(const char *src);
 int	find_n(char *str);

 #endif
