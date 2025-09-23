

#include "get_next_line.h"

size_t	ft_strlen(const char *s)

{
	int	i;

	i = 0;
	while (*s)
	{
		++i;
		++s;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		(s3[i] = s1[i]);
		++i;
	}
	while (s2[j])
	{
		(s3[i + j] = s2[j]);
		++j;
	}
	s3[i + j] = ('\0');
	return (s3);
}

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			x = (char *)(str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (x);
}

char	*ft_strdup(const char *str)

{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	while (i < len)
	{
		copy[i] = str[i];
		++i;
	}
	copy[len] = '\0';
	return (copy);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			total_size;
	unsigned char	*ptr;

	i = 0;
	total_size = count * size;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
