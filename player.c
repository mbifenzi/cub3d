#include "cub3d.h"

float    ft_line( int x, int y, int size ,float angle, int color)
{
    float r = 0;
    int or_x = x;
    int or_y = y;
	
    while (r < size)
    {
        x = or_x + (r * cos(angle));
        y = or_y + (r * sin(angle));
		if (img.data[(int)(y * 1920 + x)] == GREY || x >1920 || y > 1080)
			break;
	 	img.data[(int)(y * 1920 + x)] =  color;
        r++;
    }
	return r;
}

void    draw_dir(int x, int y);
void    draw_fov(int x, int y)
{
    float angle;
    int j = 0;
    int radius;
    angle = player.rotationangle;
    radius = 2000;
    while (j < 1920)
    {
        ft_line(x,y,radius,angle,RED);
        j++;
        angle += (M_PI / 3) / 1920;
    }
    draw_dir(x,y);
}

void    draw_dir(int x, int y)
{
    float angle;
    angle = player.rotationangle + M_PI / 6;
    ft_line(x,y,2000,angle,BLUE);
}

void    draw_circle(int x, int y)
{
    float   angle;
    int     radius;
    angle = 0;
    radius = 10;
    while (angle <= 2 * M_PI)
    {
        ft_line(x,y,radius,angle,WHITE);
        angle += (M_PI / 180);
    }
    draw_fov(x,y);
}

void     get_lines(int fd)
{
    char *line1;
   
    int i;

    i = 0;
    t = "";
    while(get_next_line(fd,&line1))
    {
        if (line1[0] != '\0')
        {
            t = ft_strjoin(t,line1);
            t = ft_strjoin(t,"\n");
            free(line1);
            line1 = NULL;
        }
    }
    t = ft_strjoin(t,line1);
    t = ft_strjoin(t,"\0");
    close(fd);
    line = ft_split(t,'\n');
}
void    draw_map()
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int useless;

    img.img_ptr = mlx_new_image(mlx.mlx_ptr, 1920,1080);
    img.data = (int *)mlx_get_data_addr(img.img_ptr, &useless,
		&useless, &useless);
    while (line[i])
    {
        x = 0;
        j = 0;
        while (line[i][j])
        {
            if(line[i][j] == '1')
            {
                ft_moraba3(x,y);
                x += map.wall_width;
            }
            else
                x +=map.wall_width;
            j++;
        }
        y+= map.wall_height;
        i++;
    }

    //printf("py = %d\n",py);
    draw_circle(player.px,player.py);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
}