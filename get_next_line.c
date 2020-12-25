
#include "get_next_line.h"
#include <fcntl.h>  // must be <unistd.h>, see `man read` 

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
int get_next_line_cleanup(char* ptr1, char* ptr2)
{
	free(ptr1);
	free(ptr2);
	return (-1);
}

// ft_strchr("abcdef", 'd') -> "def"
char*	ft_strchr(char *str, int ch)
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


char	*extract_first_line(char **remain)
{
	char	*res;
	char	*tmp;
	if (ft_strchr(*remain, '\n'))
	{
		if (!(res = save_before_n(*remain)))
			return (NULL);
		tmp = *remain;
		if (!(*remain = ft_strdup(pointer_after_n(tmp))))
		{
			free(res);
			*remain = tmp;
			return (NULL);
		}
		free(tmp);
		return (res);
	}
	res = *remain;
	*remain = NULL;
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static	char	*remain = NULL;
	int				reader;
	char			*tmp;

	if (!line) 
		return (-1);

	if (ft_strchr(remain, '\n'))
	{
		if (!(*line = save_before_n(remain)))
			return (get_next_line_cleanup(remain, *line));
		tmp = remain;
		if (!(remain = ft_strdup(pointer_after_n(remain))))
			return (get_next_line_cleanup(tmp, *line));
		free(tmp);
		return (1);
	}
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			*(ft_strchr(buffer, '\n')) = '\0';
			if (!(*line = ft_strjoin(remain ? remain : "", buffer)))
				return(get_next_line_cleanup(remain, NULL));
			
			tmp = remain;
			if (!(remain = ft_strdup(buffer + ft_strlen(buffer) + 1)))
				return (get_next_line_cleanup(tmp, *line));
			free(tmp);
			
			return (1);
		}
		tmp = remain;
		if (!(remain = ft_strjoin(remain ? remain : "", buffer)))
			return (get_next_line_cleanup(tmp, *line));
		free(tmp);
	}
	if (reader == 0)
	{
		*line = remain;
		remain = NULL;
		return (*line ? 1 : 0);
	}
	free(remain);
	return (-1);
}

int	main(int argc, char**argv)
{
	char	*line;
	int		fd = argc > 1 ? open(argv[1], O_RDONLY) : 0;
	int		status;
	
	printf("fd = %d\n", fd);

	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("status = %d, line: \"%s\"\n", status, line);
		free(line);
	}
	printf("status = %d\n", status);

	return (0);
}


// argv: [*, *, NULL]
//        \  \.
//       ./a.out
//             \.
//             first argument  

// 0 -- stdin (данные, которые вводим в консоль)
// 1 -- stdout (что печатет и выводит на экран)
// 2 -- stderr (тоже печатается на экран, но сообщает об ошибке)

// char* ptr;
// *ptr == ptr[0]
// ptr[index] --- *(ptr + index)
// index[ptr] --- *(index + ptr)
// *(argv+1) = argv[1]

//*(ft_strchr(buffer, '\n')) = '\0';
//  ~~~~~~~~~~~~~~~~~~~~~~~
//           char*
// char* ptr = buffer;
// ptr++;
// if (*ptr == '1') {...}
// *ptr = 'b';