// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <stdio.h>

// int BUFFER = 42;



// int main(int ac, char **av)
// {
// 	if ((ac != 2) || (av[1][0] == '\0'))
// 		return (1);

// 	char *src = malloc(BUFFER);
// 	if (!src)
// 	{
// 		perror("Error: ");
// 		return (1);
// 	}

// 	char *c = av[1];
// 	int len = strlen(c);

// 	char *res
// 	while ((read(0, src, BUFFER)) > 0)
// 	{
// 		int i = 0;
// 		if (c[i] && res[i] == c[i])
// 			i++;
// 		if (i == len)
// 		{
// 			int j = 0;
// 			while (j < len)
// 				res[j++] = '*';
// 			i += len;
// 		}
// 		else
// 			i++;
// 	}
// 	printf("%s", res);
// 	free(res);
// 	return (0);
// }


#include <stdio.h>



int main(int ac, char **av)
{
	if ((ac != 2) || (av[1][0] == '\0'))
		return 1;

	char *buf = malloc(BUFSIZ);
	if (!buf)
	{
		perror("Error: ");
		return 1;
	}
	int read_bytes = read(0, buf, sizeof buf);
	if (read_bytes < 0)
		return 1;
	buf[read_bytes] = '\0';

	char *read_str = buf;
	char *target = av[1][0];
	char *result = NULL;

	int target_len = strlen(target);

	while (read_str[i])
	{
		int i = 0;
		while (target[i] && read_str[i] == target[i])
			i++;
		if (i == target_len)
		{
			int j = 0;
			while (j < len)
			{
				*result++ = '*';
				j++;
			}
			read_str += target_len;
		}
		else
		{
			*result = *read_str;
			result++;
			read_str++:
		}
	}
	*result = '\0';
	printf();
}
