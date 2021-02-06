/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:10:19 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/02/06 14:46:53 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void store_data(void)
{   
    int i;
    char **ddata;

    i = 0;
    ddata = ft_split(g_tmp, '\n');
    while (ddata[i])
    {
        if (ddata[i][0] == 'R')
            ft_get_resolution(ddata[i]);
        if ((ddata[i][0] == 'F' || ddata[i][0] == 'C') && ddata[i][1] == ' ')
            ft_check_colors(ddata[i]);
        if (ft_conditions_textures(ddata[i]))
            ft_get_textures(ddata[i]);
        i++;
    }
}
void		ft_sizeofmap(void)
{
	g_biglen = 0;
	g_sizeofmap = 0;
	while (g_line[g_sizeofmap])
	{
		if (ft_strlen(g_line[g_sizeofmap]) > (size_t)g_biglen)
			g_biglen = ft_strlen(g_line[g_sizeofmap]);
		g_sizeofmap++;
	}
}

void     get_lines(int fd)
{
    char    *line1;
    int     i;

    i = 0;
    g_t = "";
    while(get_next_line(fd,&line1))
    {
        if (line1[0] != '\0')
        {
            g_t = ft_strjoin(g_t,line1);
            g_t = ft_strjoin(g_t,"\n");
            free(line1);
            line1 = NULL;
        }
    }
    g_t = ft_strjoin(g_t,line1);
    g_t = ft_strjoin(g_t,"\0");
    close(fd);
    g_line = ft_split(g_t,'\n');
    ft_sizeofmap();	
}




void    ft_read_lines(int fd)
{
    char *line;
    int i;
    int n;

    n = 1;
    i = 0;
	g_tmp = "";
    while (n != 0 && i < 8)
    {
        n = get_next_line(fd, &line);
        if (line[0] != '\0')
        {
        	g_tmp = ft_strjoin(g_tmp, line);
            if (n != 0)
            	g_tmp = ft_strjoin(g_tmp, "\n");
            free(line);
            line = NULL;
            i++;
        }
    }
    get_lines(fd);
    store_data();
    close(fd);
}

void ft_parsing(char *str)
{
	int fd;

    if ((fd = open(str, O_RDONLY)) == -1)
		ft_error("error file");
	ft_read_lines(fd);
}