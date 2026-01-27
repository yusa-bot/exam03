#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t ret = 0;
    while (s[ret])
    {
        ret++;
    }
    return (ret);
}

char *ft_strchr(char *s, int c)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != c)
        i++;
    if (s[i] == c)
        return s + i;
    else
        return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        ((char*)dest)[i] = ((char*)src)[i];
        i++;
    }
    return dest;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1;

    if (*s1 == NULL)
        size1 = 0;
    else
        size1 = ft_strlen(*s1);

    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;

    if (*s1)
        ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = '\0';

    free(*s1);
    *s1 = tmp;
    return 1;
}
int str_append_str(char **s1, char *s2)
{
    return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (d == s || n == 0)
        return dest;
    if (d < s)
    {
        size_t i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else // Copy backwards
    {
        size_t i = n;
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
    char *result = NULL;

	// 初期read
    if (buf[0] == '\0')
    {
        int read_ret = read(fd, buf, BUFFER_SIZE);
        if (read_ret <= 0)
        	return NULL;
        buf[read_ret] = '\0';
    }

	// 初期改行判定
    char *tmp = ft_strchr(buf, '\n');

    while (!tmp)
    {
		// result+buf
        if (!str_append_str(&result, buf))
            return NULL;

		// buf read
        int read_ret = read(fd, buf, BUFFER_SIZE);
        if (read_ret <= 0)
        {
            if (result && *result)
                return result;
            free (result);
            return NULL;
        }
        buf[read_ret] = '\0';

		// 改行判定
        tmp = ft_strchr(buf, '\n');
    }

	// result を 改行までにする
    if (!str_append_mem(&result, buf, tmp - buf + 1))
    {
        free(result);
        return NULL;
    }

	// buf を改行からにする
    ft_memmove(buf, tmp + 1, ft_strlen(tmp + 1) + 1);

    return result;
}


int main(int argc, char *argv[])
{
	int fd;
    char *line;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}