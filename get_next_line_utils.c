/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
 /*                                                +#+#+#+#+#+   +#+           */
 /*   Created: 2020/12/18 15:18:04 by jwasp             #+#    #+#             */
 /*   Updated: 2020/12/18 15:27:53 by jwasp            ###   ########.fr       */
 /*   Updated: 2020/12/21 21:47:56 by jwasp            ###   ########.fr       */
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

 int	find_n(char *str)
 {
 	size_t	i;

 	i = 0;
 	if (!str)
 		return (0);
 	while (str[i] != '\0')
 	{
 		if (str[i] == 10)
 			return (1);
 		i++;
 	}
 	return (0);
 }
