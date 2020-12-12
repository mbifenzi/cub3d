#include "cub3d.h"
int ft_key(int key)
{
    printf("%d\n",key);
    if (key == 126)
       py -= 20;
    mlx_destroy_image(mlx.mlx_ptr,img.img_ptr);
    draw_map();
    return 0;
}
