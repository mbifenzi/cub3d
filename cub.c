/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:05:57 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/12/01 01:08:04 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"


void    ft_moraba3(int x, int y)
{
    int i  = y; 
    int j = x; 
    
     while (i < (1080 / 14) + y)
    {
        j = x;
        while (j < (1920 / 32) + x)
        {
            //mlx_pixel_put(mlx.mlx_ptr,mlx.win,j,i,GREY);
            img.data[(i * 1920 + j)] = GREY;
            j++;
        }
        i++;
    }
    
}
int main(int argc, char **argv)
{
    
    int i = 0;
    int x = 0;
    int y = 0;
    px = 1508;
    py = 875;
   //char     *line;
    if (argc != 2)
        exit(0);
    fd = open(argv[1],O_RDONLY);
    mlx.mlx_ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "bifenzi");
    
    get_lines(fd);
      

   
    

    draw_map();
    mlx_hook(mlx.win,2,1L >> 1, ft_key, (void *) 0);
   
    mlx_loop(mlx.mlx_ptr);


}

