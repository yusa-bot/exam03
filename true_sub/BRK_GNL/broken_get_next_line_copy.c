#include "get_next_line_copy.h"

size_t ft_strlen(char *s)
{
    size_t ret = 0;
    while (*s)
    {
        s++;
        ret++;
    }
    return (ret);
}

char *ft_strchr(char *s, int c)
{
    int i = 0;
    while (s[i] != c)
        i++;
    if (s[i] == c)
        return s + i;
    else
        return NULL;
}

// destにsrcを n文字分copy
void *ft_memcpy(void *dest, const void *src, size_t n)
{
    while (--n > 0)
        ((char*)dest)[n - 1] = ((char*)src)[n - 1];
    return dest;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;

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
    if (dest > src)
        return ft_memcpy(dest, src, n);
    else if (dest == src)
        return dest;
    size_t i = ft_strlen((char*)src) - 1;
    while (i >= 0)
    {
        ((char*)dest)[i] = ((char*)src)[i];
        i--;
    }
    return dest;
}

char *get_next_line(int fd)
{
    //char *result = NULL;
    //static char buf[BUFFER_SIZE + 1] = "";

    //char *result = malloc(BUFFER_SIZE + 1);
    //if (!result)
    //    return NULL;

    static char *buf;

    //printf("len: %zu", ft_strlen(buf));
    //printf("buf: %s", buf);

    if (!buf)
        buf = strdup("");
    if (!buf)
        return NULL;

    int read_ret = 1;
    char *tmp = ft_strchr(buf, '\n');

    printf("a\n");

    while (!tmp && read_ret > 0)
    {
        if (!str_append_str(&result, buf)) // result+buf
            return NULL;
        read_ret = read(fd, buf, BUFFER_SIZE);
        if (read_ret == -1)
            return NULL;
        buf[read_ret] = 0;
    }
    if (!str_append_mem(&result, buf, tmp - buf + 1)) // result + buf(\n以降)
    {
        free(result);
        return NULL;
    }
    return result;
}

int main(void)
{
    int fd = 0;

    get_next_line(fd);

    return 0;
}
