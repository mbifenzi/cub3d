
#include "cub3d.h"

int			is_facing(int i)
{
	int		t;

	t = 0;
	if (g_ray[i].ray_facingup && !g_ray[i].was_hit_v)
		t = 1;
	if (g_ray[i].ray_facingdown && !g_ray[i].was_hit_v)
		t = 3;
	else if (g_ray[i].ray_facingright && g_ray[i].was_hit_v)
		t = 2;
	else if (g_ray[i].ray_facingleft && g_ray[i].was_hit_v)
		t = 4;
	return (t);
}

int			rgb_to_int(int r, int g, int b)
{
	int		k;

	k = (256 * 256 * r) + (256 * g) + b;
	return (k);
}

void		render_ceiling(int start, int i)
{
	int	c;

	c = -1;
	while (++c < start)
		my_mlx_pixel_put(c, i, rgb_to_int(g_color[0].color_c,
					g_color[1].color_c, g_color[2].color_c));
}

void		render_wall(int bot, int start, int i, float wall_h)
{
	float	tex_x;
	float	tex_y;
	int		bdya;
	int		color;
	int		t;

	t = is_facing(i);
	bdya = start - 1;
	 tex_x = g_ray[i].was_hit_v ? g_ray[i].wall_hity / TILE_SIZE
		: g_ray[i].wall_hitx / TILE_SIZE;
	tex_x -= (int)tex_x;
	 tex_x *= g_textures[t].text_width;
	while (++bdya < bot)
	{
		tex_y = (bdya - ((g_data.win_height / 2) - (wall_h / 2)))
			* ((float)g_textures[t].text_height / wall_h);
		color = g_textures[t].text[((int)tex_y
				* g_textures[t].text_width) + (int)tex_x];
		my_mlx_pixel_put(bdya, i, color);
	}
}

void		render_floor(int bot, int i)
{
	while (bot < g_data.win_height)
	{
		my_mlx_pixel_put(bot, i, rgb_to_int(g_color[0].color_f,
					g_color[1].color_f, g_color[2].color_f));
		bot++;
	}
}

void		ft_render(int i)
{
	int		wall_h;
	int		dp;
	int		start;
	int		bot;

	dp = (g_data.win_width / 2) / tan(FOV_ANGLE / 2);
	g_ray[i].distance *= cos(normalize_angle(g_ray[i].ray_angle
				- g_player.rotation_angle));
	wall_h = (TILE_SIZE / g_ray[i].distance) * dp;
	start = (g_data.win_height / 2) - (wall_h / 2);
	start = (start < 0) ? 0 : start;
	bot = (g_data.win_height / 2) + (wall_h / 2);
	bot = (bot > g_data.win_height) ? g_data.win_height : bot;
	render_ceiling(start, i);
	render_wall(bot, start, i, wall_h);
	render_floor(bot, i);
}
