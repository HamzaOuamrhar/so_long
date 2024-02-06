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
	size_t i = 0;
	*last = last_line(fd);
	int first = 2;
	fd = open(map_path, O_RDONLY);
	char *s = get_next_line(fd);
	if (!s)
		return(close(fd), 0);
	size_t len = ft_strlen(s);
	while(i < len - 2)
	{
		if (s[i] != '1')
			return (close(fd), 1);
		i++;
	}
	s = get_next_line(fd);
	while(s)
	{
		if (first != *last)
			if (len != ft_strlen(s))
				return(close(fd), 7);
		i = 0;
		if (first == *last)
		{
			if (len - 1 != ft_strlen(s))
				return(close(fd), 8);
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
			else if (s[i] == 'E')
				e += 1;
			else if (s[i] == 'P')
				p += 1;
			else if (s[i] != '0' && s[i] != '1')
				return (close(fd), 6);
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

void rendering(void *mlx, void *window, int width, int height, char **map_array)
{
	int k, z;
	void *image;
	int i = 0;
	int j = 0;
	int f = 0;
	int l = 0;
	while(i < height)
	{
		j = 0;
		l = 0;
		while(j < width)
		{
			image = mlx_xpm_file_to_image(mlx, "./assets/square.xpm", &k, &z);
			mlx_put_image_to_window(mlx, window, image, j, i);
			if (map_array[f][l] == '1')
				image = mlx_xpm_file_to_image(mlx, "./assets/1.xpm", &k, &z);
			else if (map_array[f][l] == 'C')
				image = mlx_xpm_file_to_image(mlx, "./assets/C.xpm", &k, &z);
			else if (map_array[f][l] == 'P')
				image = mlx_xpm_file_to_image(mlx, "./assets/P.xpm", &k, &z);
			else if (map_array[f][l] == 'E')
				image = mlx_xpm_file_to_image(mlx, "./assets/E.xpm", &k, &z);
			else
				image = mlx_xpm_file_to_image(mlx, "./assets/square.xpm", &k, &z);
			mlx_put_image_to_window(mlx, window, image, j, i);
			l++;
			j += 48;
		}
		f++;
		i += 48;
	}
}

int main(int argc, char **argv)
{
	int height;
	size_t width;
	int last;
	if (argc != 2)
		return(perror("Incorrect number of arguments!"), 1);
	char *map_path = argv[1];
	int fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(perror("Map file error opening!"), 1);
	if (check_map(fd, map_path, &last) != 5)
		return(perror("Invalid map"), 1);
	fd = open(map_path, O_RDONLY);
	char **map_array = map_to_array(fd, last);
	height = last;
	width = ft_strlen(map_array[0]) - 1;
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, (width * 48), (height * 48), "so_long");
	rendering(mlx, window, (width * 48), (height * 48), map_array);
	mlx_loop(mlx);
}