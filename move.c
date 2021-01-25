#include "cub3d.h"
void    key_press(int key)
{
     if (key == 126)
       player.walkdirection = 1;
    if (key == 125)
        player.walkdirection = -1;
    if(key == 124)
        player.turndirection = 1;
    if (key == 123)
        player.turndirection = -1;
    if (key == 2)
        player.px += 20;
    if (key == 0)
        player.px -= 20;
}
void    key_released()
{
    player.walkdirection = 0;
    player.walkdirection = 0;
    player.turndirection = 0;
    player.turndirection = 0;
   
    
}
int ft_key(int key)
{
    printf("%d\n",key);
    if (key == 53)
        exit_all();
    key_press(key);
    ft_move();    
    key_released(); 
 
    mlx_destroy_image(mlx.mlx_ptr,img.img_ptr);
    draw_map();
    return 0;
}
int     iswall(int x, int y)
{
    x = floor(x / map.wall_width);
    y = floor(y / map.wall_height);
    if (line[y][x] == '1' || y > 1080 || x > 1920 || x < 0 || y < 0 )
        return 1;
    return 0;
    
    

}

void    ft_move()
{
    //printf("%d")
    int x;
    float y;
    int a;
    int b;
    a = player.px;
    b = player.py;
  
    player.rotationangle += player.turndirection * player.rotationspeed;
    float movestep = player.walkdirection * player.movespeed;
      x = a + (cos(player.rotationangle + M_PI / 6) * movestep) * map.scale;
      y = b + (sin(player.rotationangle +  M_PI / 6) * movestep) * map.scale;
      if (!iswall(x,b))
          player.px += cos(player.rotationangle + M_PI / 6) * movestep * map.scale;

      if (!iswall(a,y))
        player.py += sin(player.rotationangle +  M_PI / 6) * movestep * map.scale;
    

}