/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
 /*                                                +#+#+#+#+#+   +#+           */
 /*   Created: 2020/12/18 15:18:00 by jwasp             #+#    #+#             */
 /*   Updated: 2020/12/21 20:01:13 by jwasp            ###   ########.fr       */
 /*   Updated: 2020/12/21 22:45:37 by jwasp            ###   ########.fr       */
 /*                                                                            */
 /* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*save_before_n(char *str)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
char	*pointer_after_n(char *buffer)
{
	size_t	i;
	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == 10)
			return (buffer + i + 1); //AAA\nBBB\nCCCC\n -> B
		i++;
	}
	return (buffer + i); //вернет на конец буффера
}
int		free_str(char *str)
{
	free (str);
	return (-1);
}
int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*remain = NULL;
	int				reader;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (!(*line = (char *)malloc(1))))
		return (-1);
	**line = '\0';
	if (remain && find_n(remain))
	{
		*line = save_before_n(remain);
		remain = ft_strdup(pointer_after_n(remain));
		free(*line);
		if (!(*line = save_before_n(remain)))
			return (free_str(remain));
		tmp = remain;
		if (!(remain = ft_strdup(pointer_after_n(remain))))
			return (free_str(tmp));
		free(tmp);
		return (1);
	}
	if (!remain)
		if (!(remain = ft_strdup("")))
			return (free_str(remain));
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (find_n(buffer))
		{
			remain = save_before_n(buffer);
			*line = ft_strjoin("", remain);
			free(remain);
			remain = ft_strdup(pointer_after_n(buffer));
			if (!(remain = save_before_n(buffer)))
				return (-1);
			//free(*line);
			if (!(*line = ft_strjoin("", remain)))
				return (free_str(remain));
			free(remain);
			if (!(remain = ft_strdup(pointer_after_n(buffer))))
				return (-1);
			break ;
		}
		remain = ft_strjoin(remain, buffer);
		tmp = remain;
		if (!(remain = ft_strjoin(remain, buffer)))
			return (-1);
		free(tmp);
		tmp = NULL;
	}
	if (reader == -1 || reader == 0)
	{
 		if (reader == -1)
 			free(*line);
 		free(remain);
 		remain = NULL;
 		return (0);
 	}
	return (1);
}
int	main(void)
{
	char	*line;
	//int		fd = open("Martin_Eden.txt", O_RDONLY);
	int		fd = open("fill.txt", O_RDONLY);
	int		i;
	int		c = 0;

	while ((i = get_next_line(fd, &line)) && c < 30)
	{
		printf("i = %d %s\n\n", i, line);
		free(line);
		c++;
	}
	printf("i = %d %s\n", i, line);
	free(line);
	line = NULL;

	//sleep(50);
	return (0);
}
