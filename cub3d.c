#include "cub3d.h"


void    ft_error(char *str)
{
    printf("Error\n");
    printf("%s\n", str);
    exit(0);
}

void		ft_check_cub(char *str)
{
	int		i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".cub", 5) != 0)
		ft_error("Error\nle fichier ne fini pas par .cub");
}

void		ft_init(void)
{
	int		i;

	i = 0;
	g_data.win_width = -1;
	g_data.win_height = -1;
	while (i < 5)
	{
		g_textures[i].text_width = 0;
		g_textures[i].text_height = 0;
		g_textures[i].texture = "";
		i++;
	}
	i = 0;
	while (i < 3)
	{
		g_color[i].color_f = -1;
		g_color[i].color_c = -1;
		i++;
	}
}



void		ft_color(char **color, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (color[i])
		i++;
	if (i != 3)
	{
		//ft_free2(color);
		ft_error("Error\nProblem in the arguments of color");
	}
	i = -1;
	if (*(str + 1) != ' ')
		ft_error("Error\nun faut caractere apres le F ou C");
	while (++i < 3)
	{
		j = -1;
		while (color[i][++j])
		{
			if (color[i][j] < '0' || color[i][j] > '9')
				ft_error("Error\nLes couleurs Ne Sont Pas Bien Defini");
		}
	}
}

void		ft_nbrofdata(char **data, int i)
{
	int		j;
	int		r;

	j = 0;
	r = 0;
	if (i != 2)
	{
		//////ft_free2(data);
		printf("Error\nProblem in the color of the ceiling or floor\n");
		ft_error("if you make a space between colors 'RGB' delete it please");
	}
	while (data[1][j])
	{
		if (data[1][j] == ',')
			r++;
		j++;
	}
	if (r != 2)
		ft_error("Error\nin the colors");
}

void		ft_getclr(char *str, char **color)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if ((ft_atoi(color[i]) < 0) || (ft_atoi(color[i]) > 255))
			ft_error("Error\nLes couleurs Ne Sont Pas Bien Defini");
		else if (*str == 'F')
		{
			g_color[i].color_f = ft_atoi(color[i]);
		}
		else if (*str == 'C')
		{
			g_color[i].color_c = ft_atoi(color[i]);
		}
	}
	////ft_free2(color);
}

void		ft_datatxtnbr(char **data, int i)
{
	(void)data;
	if (i != 2)
	{
		//ft_free2(data);
		ft_error("Error\nprobleme in the path of textures");
	}
}

void		ft_check_colors(char *str)
{
	char	**data;
	char	**color;
	int		i;

	i = 0;
	if (g_color[0].color_c != -1 && *str == 'C')
		ft_error("Error\ncolor of the ceiling is already filled");
	if (g_color[0].color_f != -1 && *str == 'F')
		ft_error("Error\ncolor of the floor is already filled");
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	ft_nbrofdata(data, i);
	color = ft_split(data[1], ',');
	////////ft_free2(data);
	ft_color(color, str);
	ft_getclr(str, color);
	g_mapindicator++;
}

void ft_get_textures(char *str)
{
	char	**data;
	int		i;

	i = 0;
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	ft_datatxtnbr(data, i);
	if (*str == 'S' && *(str + 1) == 32)
		g_textures[S].texture = ft_strdup(data[1]);
	else if (*str == 'S' && *(str + 1) == 'O')
		g_textures[SO].texture = ft_strdup(data[1]);
	else if (*str == 'E' && *(str + 1) == 'A')
		g_textures[EA].texture = ft_strdup(data[1]);
	else if (*str == 'N' && *(str + 1) == 'O')
		g_textures[NO].texture = ft_strdup(data[1]);
	else if (*str == 'W' && *(str + 1) == 'E')
		g_textures[WE].texture = ft_strdup(data[1]);
	else
		ft_error("Error\nun faut caractere");
	////////ft_free2(data);
}

int    ft_conditions_textures(char *str)
{
    if (*str == 'N' && *(str + 1) == 'O')
		return (1);
	if (*str == 'S' && *(str + 1) == 'O')
		return (1);
	if (*str == 'W' && *(str + 1) == 'E')
		return (1);
	if (*str == 'E' && *(str + 1) == 'A')
		return (1);
	if (*str == 'S' && *(str + 1) == ' ')
		return (1);
	return (0);
}

void		ft_check_resolution_error(char *str, char **data)
{
	int		i;
	int		j;

	i = 0;
	if (*(str + 1) == ' ')
	{
		while (++i < 3)
		{
			j = -1;
			while (data[i][++j])
			{
				if (data[i][j] == '-')
					ft_error("Error\nresolution can't be negative");
				if (data[i][j] < '0' || data[i][j] > '9')
					ft_error("Error\nLa Resolution N'est Pas Bien Defini");
			}
			if (ft_atoi(data[i]) < 0)
				ft_error("Error\nresolution is invalid");
		}
	}
	else
		ft_error("Error\nun faut caractere apres le R");
}

void		ft_get_resolution(char *str)
{
	char	**data;
	int		i;

	i = 0;
	if (g_data.win_height != (-1) && g_data.win_width != (-1))
		ft_error("Error\nVous avez donner plus qu'une resolution");
	data = ft_split(str, ' ');
	while (data[i])
		i++;
	if (i != 3)
	{
		//////ft_free2(data);
		ft_error("Error\nUn Probleme Dans La Resolution");
	}
	ft_check_resolution_error(str, data);
	g_data.win_height = ft_atoi(data[2]);
	g_data.win_width = ft_atoi(data[1]);
	if (g_data.win_height > 1440)
		g_data.win_height = 1440;
	if (g_data.win_width > 2550)
		g_data.win_width = 2550;
	//////ft_free2(data);
	g_mapindicator++;
}

void	init_mlx(void)
{
	g_mlx.ptr = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.win_width,
			g_data.win_height, "cub3D");
	g_mlx.img = mlx_new_image(g_mlx.ptr, g_data.win_width, g_data.win_height);
}

void	set_rotationangle(char player_position)
{
	if (player_position == 'N')
		g_player.rotation_angle = (270 * (PI / 180));
	else if (player_position == 'S')
		g_player.rotation_angle = (90 * (PI / 180));
	else if (player_position == 'W')
		g_player.rotation_angle = (180 * (PI / 180));
	else if (player_position == 'E')
		g_player.rotation_angle = (360 * (PI / 180));
}

void	init_player(void)
{
	int		i;
	int		j;

	i = -1;
	g_player.rotation_angle = 0;
	g_sprite_c = 0;
	while (++i < g_sizeofmap)
	{
		j = -1;
		while (++j < g_biglen)
		{
			if (g_line[i][j] == 'E' || g_line[i][j] == 'N'
					|| g_line[i][j] == 'S' || g_line[i][j] == 'W')
			{
					// while(g_line[++i])
				set_rotationangle(g_line[i][j]);
				g_player.x = (j * TILE_SIZE) + TILE_SIZE / 2;
				g_player.y = (i * TILE_SIZE) + TILE_SIZE / 2;
			}
			else if (g_line[i][j] == '2')
				g_sprite_c++;
		}
	}
	g_player.rotation_speed = 3 * (PI / 180);
	g_player.move_speed = 5;
	g_player.angle = PI / 2;
}

void	init_move(void)
{
	g_player.walk_d = 0;
	g_player.turn_d = 0;
	g_player.walk_r = 0;
}

int		key_press(int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.ptr, g_mlx.win);
		exit(0);
	}
	if (key == W_KEY)
		g_player.walk_d = 1;
	if (key == S_KEY)
		g_player.walk_d = -1;
	if (key == LEFT_ARROW)
		g_player.turn_d = -1;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 1;
	if (key == D_KEY)
		g_player.walk_r = -1;
	if (key == A_KEY)
		g_player.walk_r = 1;
	return (0);
}

int		ft_exit(void)
{
	mlx_destroy_window(g_mlx.ptr, g_mlx.win);
	exit(0);
}

int		key_release(int key)
{
	int t;

	t = 0;
	if (key == ESC)
	{
		mlx_destroy_window(g_mlx.ptr, g_mlx.win);
		exit(0);
	}
	if (key == W_KEY)
		g_player.walk_d = 0;
	if (key == S_KEY)
		g_player.walk_d = 0;
	if (key == LEFT_ARROW)
		g_player.turn_d = 0;
	if (key == RIGHT_ARROW)
		g_player.turn_d = 0;
	if (key == D_KEY)
		g_player.walk_r = 0;
	if (key == A_KEY)
		g_player.walk_r = 0;
	return (0);
}

int				wall_collision(float x, float y)
{
	int			grid_x;
	int			grid_y;

	grid_x = x / TILE_SIZE;
	grid_y = y / TILE_SIZE;
	if (grid_y < 0 || grid_y >= g_sizeofmap ||
			grid_x < 0 || grid_x >= g_biglen)
		return (0);
	if (g_line[grid_y][grid_x] == '1' || g_line[grid_y][grid_x] == ' ')
		return (1);
	if (g_line[grid_y][grid_x] == '2')
		return (2);
	return (0);
}

void	ft_jareb(void)
{
	mlx_destroy_image(g_mlx.ptr, g_mlx.img);
	mlx_clear_window(g_mlx.ptr, g_mlx.win);
	g_mlx.img = mlx_new_image(g_mlx.ptr, g_data.win_width, g_data.win_height);
	g_mlx.data = (int *)mlx_get_data_addr(g_mlx.img,
			&g_mlx.bpp, &g_mlx.size_line, &g_mlx.endian);
}

float	normalize_angle(float angle)
{
	while (angle > 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	my_mlx_pixel_put(int y, int x, int color)
{
	//y *= MINIMAP;
	//x *= MINIMAP;
	if (x >= 0 && x < g_data.win_width && y >= 0
			&& y < g_data.win_height)
		g_mlx.data[(x + (y * g_data.win_width))] = color;
}

void		draw_morba3(int j, int k, int color)
{
	int		x;
	int		y;
	int		c;

	y = j + 64;
	x = k + 64;
	while (j < y)
	{
		c = k;
		while (c < x)
		{
			my_mlx_pixel_put(j, c, color);
			c++;
		}
		j++;
	}
}

void			draw_map(void)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	y = 0;
	while (y < g_sizeofmap)
	{
		x = 0;
		while (x < g_biglen)
		{
			if (g_line[y][x] == '1')
				draw_morba3(y * TILE_SIZE, x * TILE_SIZE, 0xffff00);
			if (g_line[y][x] == 'E' || g_line[y][x] == 'S'
					|| g_line[y][x] == 'N' || g_line[y][x] == 'W')
				g_line[y][x] = '0';
			x++;
		}
		y++;
	}
}

void		draw_line_of_player(void)
{
	int		k;
	float	y;
	float	x;

	k = PLAYERLINE;
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	while (k)
	{
		y = g_player.y + sin(g_player.rotation_angle) * k;
		x = g_player.x + cos(g_player.rotation_angle) * k;
		my_mlx_pixel_put(y, x, 0xffffff);
		k--;
	}
}
void		draw_player(void)
{
	float	j;
	float	zb;
	float	x;
	float	y;

	j = RAYON;

	while (j > 0)
	{
		zb = 0;
		while (zb <= 360)
		{
			x = g_player.x + j * cos(zb * g_player.angle);
			y = g_player.y + j * sin(zb * g_player.angle);
			my_mlx_pixel_put(y, x, 0xffffff);
			zb += 0.1;
		}
		j--;
	}
	draw_line_of_player();
}


void			ft_move(void)
{
	float		move_step;
	float		new_posx;
	float		new_posy;

	ft_jareb();
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	move_step = g_player.move_speed * g_player.walk_d;
	new_posy = g_player.y + sin(g_player.rotation_angle) * move_step;
	new_posx = g_player.x + cos(g_player.rotation_angle) * move_step;
	if (g_player.walk_r != 0)
	{
		move_step = g_player.move_speed * g_player.walk_r;
		new_posy = g_player.y - cos(g_player.rotation_angle) * move_step;
		new_posx = g_player.x + sin(g_player.rotation_angle) * move_step;
	}
	if (!wall_collision(new_posx, g_player.y))
		g_player.x = new_posx;
	if (!wall_collision(g_player.x, new_posy))
		g_player.y = new_posy;
	g_player.rotation_angle += g_player.turn_d * g_player.rotation_speed;
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	draw_map();
	draw_player();
	cast_all_rays();
	//ft_sprite();

}

int		ft_keys(void)
{
	mlx_hook(g_mlx.win, 2, 0, key_press, 0);
	mlx_hook(g_mlx.win, 3, 0, key_release, 0);
	mlx_hook(g_mlx.win, 17, 0L, ft_exit, 0);
	ft_move();
	mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}


int main(int ac, char **av)
{

    if (ac > 3 || ac < 2)
        ft_error("arguments");
    ft_check_cub(av[1]);
	ft_init();
	ft_parsing(av[1]);
	init_mlx();	

	init_player();

	init_move();

	// TODO: getting textures
	mlx_loop_hook(g_mlx.ptr, ft_keys, (void*)0);
	mlx_loop(g_mlx.ptr);
}