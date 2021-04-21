#include "get_next_line.h"

static void	read_line(int fd, int *ret, char **end_line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	while (!ft_strchr(*end_line, '\n') && *ret > 0)
	{
		*ret = (int)read(fd, buffer, BUFFER_SIZE);
		buffer[*ret] = 0;
		tmp = ft_strjoin(*end_line, buffer);
		if (*end_line)
		{
			free(*end_line);
			*end_line = NULL;
		}
		*end_line = tmp;
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*end_line;
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!end_line)
		end_line = ft_calloc(1, sizeof(*end_line));
	ret = 1;
	read_line(fd, &ret, &end_line);
	if (ret == 0)
	{
		*line = ft_strdup(end_line);
		free(end_line);
		end_line = NULL;
		return (0);
	}
	if (ret > 0)
	{
		*line = ft_substr(end_line, 0, (ft_strchr(end_line, '\n') - end_line));
		tmp = ft_strdup(end_line + ft_strlen(*line) + 1);
		free(end_line);
		end_line = tmp;
		return (1);
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len + 1)
	{
		str[len] = s[len];
		len--;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	str = malloc((len + 1) * sizeof(*str));
	if (0 == str)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
