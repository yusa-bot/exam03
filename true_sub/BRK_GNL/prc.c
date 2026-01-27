#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	if (!s)
		return 0;
	size_t len = 0;
	while (s[len])
		len++;
	return len;
}

char *ft_strchr(const char *s, int c)
{
	if (!s)
		return NULL;

	int i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (char *)s;
		i++;
	}
	if ((char)c == '\0')
		return s[i];
	return NULL;
}

char *ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!src || !dst)
		return NULL;

	int i = 0;
	while (src[i] && i <= n)
	{
		((char *dst))[i] == ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';

	return dst;
}

char *get_next_line(int fd)
{
	
}

int main(void)
[
	int fd = 0;

	while (1)
	{
		char *line = get_next_line(fd);
		if (!line)
			break;
		printf("line: %s", line);
	}
	close(fd);
	return 0;
]