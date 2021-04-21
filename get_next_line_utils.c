#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;

	us = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(us + i) = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = (size_t *)malloc(nmemb * size);
	if (tmp)
		ft_memset(tmp, 0, nmemb * size);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
		if (!s[i++])
			return (0);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(*str) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i--;
	while (++i < len1 + len2)
		str[i] = s2[i - len1];
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
