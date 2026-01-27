#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	print_error(char **dest, char **str, int free1, int free2)
{
	if(free1 == 1)
		free(dest);
	if(free2 == 1)
		free(str);
	perror("Error: ");
	exit(1);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *join = malloc(strlen(s1) + strlen(s2) + 1);
	if (!join)
		return (NULL);

	char *result = join;

	while (*s1)
		*join++ = *s1++;

	while (*s2)
		*join++ = *s2++;

	*join = '\0';
	return (result);
}


int main(int ac, char **av)
{
	if (ac !=2 || av[1][0] == '\0')
		return 1;

	char *str = malloc(1);
	if (!str_append_str)
		return 0;

	char *buf = malloc(BUFSIZ);
	if (!buf)
		return 0;

	char *tmp = buf;

	int read_bytes = 1;

	char *target = av[1];
	int target_len = strlen(target);

	int i;
	while (read_bytes > 0)
	{
		read_bytes = read(0, buf, BUFSIZ - 1);
		if (read_bytes < 0)
			return 0;
		buf[read_bytes] = '\0';

		char *tmp = ft_strjoin(str, buf);
		if (!tmp)
			return 0;

		free(str);
		str = tmp;
	}
	free(buf);

	char *result = malloc(strlen(str) + 1);
	if (!result)
		return NULL;

	while (*str)
	{
		i = 0;
		while (target[i] && str[i] == target[i])
			i++;
		if (i == target_len)
		{
			int j = 0;
			while (j <= target_len)
			{
				*result++  = '*';
				j++;
			}
			*str += target_len;
		}
		*result++ = *src++;
	}
	*result = '\0';

	free(str);

	printf("buf: %s\n", result);

	free(result);
	return 0;
}