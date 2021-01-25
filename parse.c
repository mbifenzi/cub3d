/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:19:00 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/01/25 15:55:05 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void store_data();
void  fucking_data();
void    ft_error(char *error)
{
    printf("%s", error);
    exit(0);
}
void    ft_read_lines(int fd)
{
    char *line2;
    int i;
    int n;

    n = 1;
    i = 0;
    temp = "";
    while (n != 0 && i < 8)
    {
        n = get_next_line(fd, &line2);
        if (line2[0] != '\0')
        {
            temp = ft_strjoin(temp, line2);
            if (n != 0)
                temp = ft_strjoin(temp, "\n");
            free(line2);
            line2 = NULL;
            i++;
        }
    }
    get_lines(fd);
    store_data();
    close(fd);
}

void store_data(void)
{   
    int i;

    i = 0;
    data = ft_split(temp, '\n');
    while (data[i])
    {
        printf("%d ----------- %s\n", i, data[i]);
        i++;
    }
    fucking_data();
}

int     get_resolution()
{   
    int     k;
    char    *width;
    char    *height;

    while ((data[g_p.l1][g_p.l2] =! '\n' || data[g_p.l1]) && k <= 1)
    {
        while (data[g_p.l1][g_p.l2] == ' ')
            g_p.l2++;
        while (ft_isdigit(data[g_p.l1][g_p.l2]))
        {
            *g_p.width = ft_atoi(&data[g_p.l1][g_p.l2]);
            g_p.width++;
            g_p.l2++;
            if (k == 0)
                k = 1;
        }
        while (ft_isdigit(data[g_p.l1][g_p.l2]) && k == 1)
        {
            *g_p.height = ft_atoi(&data[g_p.l1][g_p.l2]);
            g_p.height++;
            g_p.l2++;
        }
        if (!ft_isdigit(data[g_p.l1][g_p.l2]) && data[g_p.l1][g_p.l2] != ' ')
            return(-1);
    }
    return (1);
}

int     get_east()
{
   // g_p.l2 += 2;
    if (data[g_p.l1][g_p.l2] == '\0')
        return (-1);
  
   char **a;
   a = ft_split(data[g_p.l1], ' ');
    if (a[0] == "EA")
    {   
        if(a[1])
        {
            g_p.east = a[1];
            return (1);
        }
    }
    if (a[2])
        return (-1);
}

int    get_north()
{
    char    **a;
    if (data[g_p.l1][g_p.l2] == '\0')
        return (-1);
  
    a = ft_split(data[g_p.l1], ' ');
    if (a[0] == "NO")
    {
        g_p.east = a[1];
        return (1);
    }
    if (a[2])
        return(-1);
}

int     get_data(char c)
{
    g_p.l2 = 0;
    if (c == 'R')
        if(get_resolution() < 0)
            return(-1);
    if (c == 'E')
        get_east();
    printf("%s\n",g_p.east);
   // if (c == 'N')
     //   get_north();
    return (1);
}

void    fucking_data()
{
    g_p.l1 = 0;
    g_p.l2 = 0;

    while (data[g_p.l1])
    {
        if (ft_strchr( "RNSWESFC",data[g_p.l1][g_p.l2]) && ft_strchr( " OEA",data[g_p.l1][1]))
            get_data(data[g_p.l1][g_p.l2]);
        else
            ft_error("Error\n data insuffisante\n");
        g_p.l1++;
    }
}

