/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:05:57 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/01/25 15:46:57 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_moraba3(int x, int y)
{
    int i  = y;
    int j = x;

     while (i <= (map.wall_height) + y)
    {
        j = x;
        while (j <= (map.wall_width) + x)
        {
            //mlx_pixel_put(mlx.mlx_ptr,mlx.win,j,i,GREY);
            img.data[(i * 1920 + j)] = GREY;
            j++;
        }
        i++;
    }
    
}
void    exit_all(){
if (mlx.mlx_ptr && mlx.win)
		mlx_destroy_window(mlx.mlx_ptr, mlx.win);
    exit(0);
}

void     player_data()
{
    player.rotationangle = (3 * M_PI) / 2 - M_PI / 6;
    player.walkdirection = 0;
    player.turndirection = 0;
    player.movespeed = 20;
    player.rotationspeed =  10 * (M_PI / 180);
}
int main(int argc, char **argv)
{
    int i = 0;
    int x = 0;
    int y = 0;
    
    map.scale = 1;
    player.px = 1508;
    player.py = 875;
    map.wall_height = (1080 / 14) * map.scale;
    map.wall_width = (1920 / 33) * map.scale;
    if (argc != 2)
        exit(0);
    fd = open(argv[1],O_RDONLY);
    ft_read_lines(fd);
    mlx.mlx_ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "bifenzi");
    player_data();
    //get_lines(fd);
    draw_map();
    mlx_key_hook(mlx.win,ft_key, (void *) 0);
   
    mlx_loop(mlx.mlx_ptr);
}