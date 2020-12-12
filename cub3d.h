#ifndef     FT_STRUCT_H
# define     FT_STRUCT_H
#include "mlx.h"
#include "fcntl.h"
#include <math.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"
# define BLUE 255
# define RED 16711680
# define WHITE 16777215
# define BLACK 0
# define GREEN 65280
# define YELLOW 16776960
# define GREY 6579300
//void    *mlx_ptr;
  //  void    *win;


typedef struct	s_img
{
	void		*img_ptr;
	int			*data; //Here you got an int * even though mlx_get_data_addr returns
						//a char *, i'll talk more about this in the .c file.
//Here are the 3 "useless" variables. You can find more informations about these in the man page.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

/*
 Here is my main struct containing every variables needed by the MLX.
 - mlx_ptr stores the return value of mlx_init
 - win stores the return value of mlx_new_window
 - img will store everything we need for the image part, the struct is described above.
 */
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;

}				t_mlx;

t_img img;
t_mlx mlx;
int px;
int py;
int fd;
char *t;
void    draw_circle(int x, int y);
void    draw_map();
int     ft_key(int key);
void    ft_moraba3(int x, int y);
void	get_lines(int fd);


#endif
