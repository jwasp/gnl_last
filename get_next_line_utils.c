/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:35:51 by jwasp             #+#    #+#             */
/*   Updated: 2021/01/04 17:38:34 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sumstr;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sumstr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!sumstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		sumstr[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		sumstr[i] = *((char *)s2++);
		i++;
	}
	sumstr[i] = '\0';
	return (sumstr);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *str, int ch)
{
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
