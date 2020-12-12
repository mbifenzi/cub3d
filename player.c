#include "cub3d.h"

float    ft_line( int x, int y, int size ,float angle, int color)
{
    float r = 0;
    int or_x = x;
    int or_y = y;
	
	//ft_printf("len = %d --------- line =%d\n",map.parser->len, map.parser->line_nbr);
    while (r < size)
    {
        x = or_x + (r * cos(angle));
        y = or_y + (r * sin(angle));
	
		//ft_printf("i = %d ---------- j =%d\n",i, j);
		if (img.data[(int)(y * 1920 + x)] == GREY || x >1920 || y > 1080)
			break;
	 	img.data[(int)(y * 1920 + x)] =  color;
		
		 //mlx_pixel_put(mlx.mlx_ptr,mlx.win,x,y,color);
	
        r++;
    }
	return r;
	//printf("-----------------------------------------------------------%d\n",r);
}
void  draw_fov(int x, int y)
{
    float angle;
    int j = 0;
    int radius;
    angle = -M_PI / 2 - M_PI / 6;
    radius = 2000;
    while (j < 1920)
    {
        ft_line(x,y,radius,angle,RED);
        j++;
        angle += (M_PI / 3) / 1920;
    }
}
void  draw_circle(int x, int y)
{
    float angle;
    //int j = 0;
    int radius;
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
    char *line;
   
    int i;

    i = 0;
    t = "";
    while(get_next_line(fd,&line))
    {

        t = ft_strjoin(t,line);
       t = ft_strjoin(t,"\n");
       // b++;
    }
    //get_next_line(fd,&line);
    t = ft_strjoin(t,line);
    t = ft_strjoin(t,"\0");
    close(fd);
   
    
    
}
void    draw_map()
{
     int i = 0;
     int j = 0;
    int x = 0;
    int y = 0;
    char **line;
    line = ft_split(t,'\n');
     img.img_ptr = mlx_new_image(mlx.mlx_ptr, 1920,1080);
   img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp,
		&img.size_l, &img.endian);
    //printf("%s\n",line[13]);
    while (line[i])
    {  
        
        x = 0;
    
        //printf("%s\n",line[i]);
        j = 0;
    while (line[i][j])
    {
        
        if(line[i][j] == '1')
        {
            ft_moraba3(x,y);
            x += (1920/32);
        }
        else
            x +=(1920/32);
        j++;
    }
    y+=(1080/14);
    i++;
    }
   // get_next_line(fd,&line);
    
   // y+=(1080/14);
    
   /* while (line[i])
    {
        
        if(line[i] == '1')
        {
            ft_moraba3(x,y);
            x += (1920/32);
        }
        else
            x +=(1920/32);
        i++;
    }*/
     printf("py = %d\n",py);
    draw_circle(px,py);
     mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
    
    
}