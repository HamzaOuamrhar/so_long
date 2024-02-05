#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"

int last_line(int fd)
{
	int i = 0;
	char *s = get_next_line(fd);
	while(s)
	{
		i++;
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int check_map(int fd, char *map_path, int *last)
{
	int e = 0;
	int c = 0;
	int p = 0;
	int i = 0;
	*last = last_line(fd);
	int first = 2;
	fd = open(map_path, O_RDONLY);
	char *s = get_next_line(fd);
	if (!s)
		return(close(fd), 0);
	int len = ft_strlen(s);
	while(i < len - 2)
	{
		if (s[i] != '1')
			return (close(fd), 1);
		i++;
	}
	s = get_next_line(fd);
	while(s)
	{
		i = 0;
		if (first == *last)
		{
			while(i < len - 1)
			{
				if (s[i] != '1')
					return (close(fd), 3);
				i++;
			}
		}
		first++;
		if (s[0] != '1' || s[len - 2] != '1')
				return(close(fd), 2);
		while(i < len - 2)
		{
			if (s[i] == 'C')
				c += 1;
			if (s[i] == 'E')
				e += 1;
			if (s[i] == 'P')
				p += 1;
			i++;
		}
		s = get_next_line(fd);
	}
	if (!c || e != 1 || p != 1)
		return (close(fd), 4);
	return (close(fd), 5);
}

char **map_to_array(int fd, int last)
{
	int i = 0;
	char **map_array = (char **)malloc((last + 1) * sizeof(char *));
	while(i < last)
	{
		map_array[i] = get_next_line(fd);
		i++;
	}
	map_array[i] = NULL;
	return(map_array);
}

int main(int argc, char **argv)
{
	int last;
	if (argc != 2)
		return(perror("Incorrect number of arguments!"), 1);
	char *map_path = argv[1];
	int fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(perror("Map file error opening!"), 1);
	if (!check_map(fd, map_path, &last))
		return(perror("Invalid map"), 1);
	fd = open(map_path, O_RDONLY);
	char **map_array = map_to_array(fd, last);
	int i = 0;
	while(map_array[i])
	{
		printf("%s", map_array[i]);
		i++;
	}
	// int k, z;
	// void *mlx = mlx_init();
	// void *window = mlx_new_window(mlx, 480, 480, "so_long");
	// void *image = mlx_xpm_file_to_image(mlx, "./assets/dragon.xpm", &k, &z);
	// int i = 0, j = 0;
	// while(i < 480)
	// {
	// 	j = 0;
	// 	while(j < 480)
	// 	{
	// 		mlx_put_image_to_window(mlx, window, image, j, i);
	// 		j += 48;
	// 	}
	// 	i += 48;
	// }
	// mlx_loop(mlx);
}