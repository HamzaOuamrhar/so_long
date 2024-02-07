#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"
#include "./Libft/libft.h"

typedef struct mlx_data
{
	void *mlx;
	void *window;
	char **map_array;
	void *player_img;
	void *wall_img;
	void *col_img;
	void *back_img;
	void *exit_img;
	int xp;
	int yp;
	int collectibles;
	int collected;
	int moves;
}	mlx_data;

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

int check_map(int fd, char *map_path, int *last, mlx_data *data)
{
	int e = 0;
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
				data->collectibles += 1;
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
	if (!data->collectibles|| e != 1 || p != 1)
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

void rendering(mlx_data *data, int width, int height)
{
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
			mlx_put_image_to_window(data->mlx, data->window, data->back_img, j, i);
			if (data->map_array[f][l] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall_img, j, i);
			else if (data->map_array[f][l] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->col_img, j, i);
			else if (data->map_array[f][l] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->window, data->player_img, j, i);
				data->xp = l;
				data->yp = f;
			}
			else if (data->map_array[f][l] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit_img, j, i);
			else
				mlx_put_image_to_window(data->mlx, data->window, data->back_img, j, i);
			l++;
			j += 48;
		}
		f++;
		i += 48;
	}
}

void print_moves_count(mlx_data *data)
{
	data->moves += 1;
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
}

int key_pressed_handler(int key, mlx_data *data)
{
	if (key == 126)
	{
		if (data->map_array[data->yp - 1][data->xp] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48), (data->yp * 48 - 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		data->yp -= 1;
	}
	else if (key == 125)
	{
		if (data->map_array[data->yp + 1][data->xp] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48), (data->yp * 48 + 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		data->yp += 1;
	}
	else if (key == 124)
	{
		if (data->map_array[data->yp][data->xp + 1] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48 + 48), (data->yp * 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		data->xp += 1;
	}
	else if (key == 123)
	{
		if (data->map_array[data->yp][data->xp - 1] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48 - 48), (data->yp * 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		data->xp -= 1;
	}
	else if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->window);
		free(data->mlx);
		exit(0);
	}
	if (data->map_array[data->yp][data->xp] == 'C')
	{
		data->collected += 1;
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48), (data->yp * 48));
		return(1);
	}
	else if (data->map_array[data->yp][data->xp] == 'E')
	{
		if (data->collected == data->collectibles)
		{
			mlx_destroy_window(data->mlx, data->window);
			free(data->mlx);
			exit(0);
		}
		else
			return (1);
	}
	return (0);
}

int open_and_validate_images(mlx_data *data)
{
	int k;
	int z;
	data->back_img = mlx_xpm_file_to_image(data->mlx, "./textures/square.xpm", &k, &z);
	data->col_img = mlx_xpm_file_to_image(data->mlx, "./textures/C.xpm", &k, &z);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./textures/E.xpm", &k, &z);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./textures/P.xpm", &k, &z);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "./textures/1.xpm", &k, &z);
	if (!data->back_img || !data->col_img || !data->exit_img || !data->player_img || !data->wall_img)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	mlx_data data;
	int height;
	size_t width;
	int last;
	if (argc != 2)
		return(perror("Incorrect number of arguments!"), 1);
	char *map_path = argv[1];
	int fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(perror("Map file error opening!"), 1);
	if (check_map(fd, map_path, &last, &data) != 5)
		return(perror("Invalid map"), 1);
	fd = open(map_path, O_RDONLY);
	data.map_array = map_to_array(fd, last);
	height = last;
	width = ft_strlen(data.map_array[0]) - 1;
	data.mlx = mlx_init();
	if (!data.mlx)
		return(perror("Mlx pointer error!"), 1);
	data.window = mlx_new_window(data.mlx, (width * 48), (height * 48), "so_long");
	if (!data.window)
		return(free(data.window), perror("Window error"), 1);
	if (!open_and_validate_images(&data))
		return(perror("Asset error!"), 1);
	rendering(&data, (width * 48), (height * 48));
	mlx_hook(data.window, 2, 0, &key_pressed_handler, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
}