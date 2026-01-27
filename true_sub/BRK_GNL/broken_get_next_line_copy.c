#include "get_next_line_copy.h"

size_t ft_strlen(const char *s)
{
	if (!s)
		return 0;

	size_t len = 0;

    while (s[len])
        len++;

    return (len);
}

char *ft_strchr(const char *s, int c)
{
	if (!s)
		return NULL;

    int i = 0;

    while (s[i])
	{
		if (s[i] == (char)c)
			return (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		return (char *)s + i;

	return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{

	char *d = dest;
	const char *s = src;

	int i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}

	return d;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1;

	if (*s1 == NULL)
		size1 = 0;
	size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;

	if (*s1)
	    ft_memcpy(tmp, *s1, size1); // tmpにs1を size1文字分copy
    ft_memcpy(tmp + size1, s2, size2); // tmp+size1にs2を size2文字分copy
    tmp[size1 + size2] = '\0';
    // -> s1+s2+\0

    free(*s1);
    *s1 = tmp;
    return 1;
}
int str_append_str(char **s1, char *s2)
{
    return str_append_mem(s1, s2, ft_strlen(s2)); // -> s1+s2
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	if (d == s || n == 0)
		return dest;

	size_t i = 0;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return dest;
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1] = "";
    char *ret = NULL;

	int read_ret = 0;
	if (buf[0] == '\0')
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret <= 0)
			return NULL;
		buf[read_ret] = '\0';
	}

    char *tmp = ft_strchr(buf, '\n');

    while (!tmp)
    {
        if (!str_append_str(&ret, buf))
            return NULL;

        read_ret = read(fd, buf, BUFFER_SIZE);
        if (read_ret <= 0)
		{
			if (ret && *ret)
				return ret;
            return NULL;
		}
        buf[read_ret] = '\0';

		tmp = ft_strchr(buf, '\n');
    }
    if (!str_append_mem(&ret, buf, tmp - buf + 1))
    {
        free(ret);
        return NULL;
    }
	ft_memmove(&buf, tmp + 1, ft_strlen(tmp + 1) + 1);
    return ret;
}

int main(void)
{
    // int fd = 0;
	int fd = open("/home/ayusa/42/exam03/test2.txt", O_RDONLY);

	int i = 1;
	while (1)
	{
		char *line = get_next_line(fd);
		if (!line)
			break;
		printf("line[%d]: %s", i, line);
		i++;
	}

	close(fd);
    return 0;
}
