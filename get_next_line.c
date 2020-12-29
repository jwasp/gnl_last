
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:41:51 by jwasp             #+#    #+#             */
/*   Updated: 2020/12/29 19:29:12 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_before_n(char *str)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}


char	*extract_first_line(char **remain)
{
	char	*res;
	char	*tmp;
	if (*remain == NULL)
	{
		res = ft_strdup("");
		return (res);
	}
	if ((!ft_strchr(*remain, '\n') || (*(ft_strchr(*remain, '\n') + 1) == '\0')))
	{
		res = save_before_n(*remain);
		free(*remain);
		*remain = NULL;
		return (res);
	}
	if (!(res = save_before_n(*remain)))
		return (NULL);
	tmp = *remain;
	if (!(*remain = ft_strdup(ft_strchr(tmp, '\n') + 1)))
	{
		free(res);
		*remain = tmp;
		return (NULL);
	}
	free(tmp);
	return (res);
}
int		check_reader(char **line, char **remain, int reader)
{
	if (reader < 0)
	{
		free(*remain);
		return (-1);
	}
	if (reader == 0)
	{
		if (!(*line = extract_first_line(remain)))
		{
			free(*remain);
			return (-1);
		}
		if (!*remain)
			return (0);
	}
	return ((*line = extract_first_line(remain)) ? 1 : -1);	
}

char	*join_and_always_free_first(char *str1, char *str2)
{
	char	*res;
	res = ft_strjoin(str1 ? str1 : "", str2 ? str2 : "");
	free(str1);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*remain = NULL;
	int				reader;
	int				flag;

	if (!line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	flag = 0;
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (!(remain = join_and_always_free_first(remain, buffer)))
			return (-1);
		if (flag == 1)
			break;
		flag = ((ft_strchr(remain, '\n')) ? 1 : 0);
	}
	return (check_reader(line, &remain, reader));
}
