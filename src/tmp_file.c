#include "../inc/cub.h"

#define MAX_LINE_LEN 1024

void	tmp_map(t_map *map, const char *filename)
{
	FILE	*file;
	char	buffer[MAX_LINE_LEN];
	size_t	lines_alloc = 10;
	size_t	line_count = 0;
	size_t	max_width = 0;

	map->map = malloc(sizeof(char *) * lines_alloc);
	if (!map->map)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (!file)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, MAX_LINE_LEN, file))
	{
		size_t	len;

		// remove newline se houver
		len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		len = strlen(buffer); // recalcula depois de remover o \n

		if (line_count >= lines_alloc)
		{
			lines_alloc *= 2;
			map->map = realloc(map->map, sizeof(char *) * lines_alloc);
			if (!map->map)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		map->map[line_count] = strdup(buffer);
		if (!map->map[line_count])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		if (len > max_width)
			max_width = len;

		line_count++;
	}
	fclose(file);
}
