#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53

# define TILE_SIZE 64

# define PI 3.14159265
# define TWO_PI 6.28318530
# define RAYON 5
# define PLAYERLINE 50
# define FOV_ANGLE 1.04719755

# define BUFFER_SIZE 32
# define S 0
# define NO 3
# define EA 4
# define SO 1
# define WE 2

/*
**(60 * (PI / 180))
*/
/*
**THIS STRUCTURE IS MY MAIN MLX STRUCTURE
*/
typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct	s_player
{
	float		x;
	float		y;
	float		rotation_angle;
	float		rotation_speed;
	int			walk_d;
	int			turn_d;
	int			walk_r;
	float		move_speed;
	float		angle;
}				t_player;

typedef struct	s_ray
{
	float		ray_angle;
	float		wall_hitx;
	float		wall_hity;
	float		distance;
	int			was_hit_v;
	int			ray_facingup;
	int			ray_facingdown;
	int			ray_facingright;
	int			ray_facingleft;
	int			wall_hit_content;
}				t_ray;

typedef struct	s_tray
{
	int			ray_facingup;
	int			ray_facingdown;
	int			ray_facingright;
	int			ray_facingleft;
	int			h_wallhit;
	float		h_wallhit_x;
	float		h_wallhit_y;
	int			h_wallcontent;
	float		h_hit_distance;
	float		v_hit_distance;
	float		inter_v_x;
	float		inter_v_y;
	float		inter_h_x;
	float		inter_h_y;
	int			v_wallhit;
	float		v_wallhit_x;
	float		v_wallhit_y;
	int			v_wallcontent;
	float		xtocheck;
	float		ytocheck;
}				t_tray;

typedef	struct			s_textures
{
	int					text_width;
	int					text_height;
	int					*text;
	char				*texture;
}						t_textures;
typedef	struct			s_data
{
	int					win_width;
	int					win_height;
}						t_data;

typedef struct	s_p
{
	int			l1;
	int 		l2;
	char 		*east;
	char		*north;
}				t_p;

typedef	struct			s_color
{
	int					color_f;
	int					color_c;
}						t_color;

typedef struct			s_sprite
{
	void				*ptr;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
	float				x;
	float				y;
	float				distance;
}						t_sprite;
/*
**MAP
*/
char					**g_map;
int						g_sizeofmap;
int						g_biglen;
char					*g_str;
int						g_nbp;
t_sprite				**g_sprite;
/*
**SPT
*/
t_sprite				**g_sprite;

/*
**MAP INDICATOR TO START THE INIT OF THE MAP
*/
int						g_mapindicator;
t_data					g_data;
t_color					g_color[3];
t_textures				g_textures[5];
int						g_sprite_c;
char					*g_tmp;
char					**g_ddata;
char					*g_t;
char					**g_line;
t_p						g_p;
t_tray					g_tray;
t_ray					g_ray[2550];
t_mlx					g_mlx;
t_player				g_player;


void    	ft_pars(char *str);
char		*ft_strchr(const char *s, int c);
int			remplir_line(char **line, char **str, int len);
int			remplir_fin(char **line, char **str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);
void		ft_get_resolution(char *str);
void		ft_check_colors(char *str);
int    		ft_conditions_textures(char *str);
void 		ft_get_textures(char *str);
void    	ft_error(char *str);
void 		ft_parsing(char *str);
void		remplir_gray(float ray_angle, int strip_id);
void		cast_ray(float ray_angle, int strip_id);
void		cast_all_rays(void);
void    	ft_error(char *str);
void		ft_check_cub(char *str);
void		ft_init(void);
void		ft_color(char **color, char *str);
void		ft_nbrofdata(char **data, int i);
void		ft_datatxtnbr(char **data, int i);
void		ft_check_colors(char *str);
void		ft_get_textures(char *str);
void		ft_get_texture(void);
int    		ft_conditions_textures(char *str);
void		ft_check_resolution_error(char *str, char **data);
void		ft_get_resolution(char *str);
void		init_mlx(void);
void		set_rotationangle(char player_position);
void		init_player(void);
void		init_move(void);
int			key_press(int key);
int			ft_exit(void);
int			key_release(int key);
int			wall_collision(float x, float y);
float		normalize_angle(float angle);
void		my_mlx_pixel_put(int y, int x, int color);
void		render_ceiling(int start, int i);
void		render_wall(int bot, int start, int i, float wall_h);
void		render_floor(int bot, int i);
void		ft_render(int i);
void		bmp_save(void);
void		ft_sprite(void);
float		distancebetweenpts(float xd, float yd, float xf, float yf);
void    ft_secure_map();
void    ft_secure_map2();
void    ft_secure_map3();
void    ft_single_player();

#endif