#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int BUFFER = 42;



int main(int ac, char **av)
{
	if ((ac != 2) || (av[1][0] == '\0'))
		return (1);

	char *src = malloc(BUFFER);
	if (!src)
	{
		perror("Error: ");
		return (1);
	}

	char *c = av[1];
	int len = strlen(c);

	char *res
	while ((read(0, src, BUFFER)) > 0)
	{
		int i = 0;
		if (c[i] && res[i] == c[i])
			i++;
		if (i == len)
		{
			int j = 0;
			while (j < len)
				res[j++] = '*';
			i += len;
		}
		else
			i++;
	}
	printf("%s", res);
	free(res);
	return (0);
}
