#include "cub3d.h"
void    ft_single_player()
{
    int i;
    int j;
    int player;

    player = 1;
    i = 0;
    j = 0;
    while (g_line[i])
    {
        while (g_line[i][j])
        {
            if ((g_line[i][j] == 'E' || g_line[i][j] == 'W' || g_line[i][j] == 'N' || g_line[i][j] == 'S') && player == 2)
            {
                ft_error("kayn joj le33aba");
                exit(0);
            }
            if ((g_line[i][j] == 'E' || g_line[i][j] == 'W' || g_line[i][j] == 'N' || g_line[i][j] == 'S') && player == 1)
                player = 2;
            j++;
        }
        i++;
        j = 0;
    }
}
void    ft_secure_map3()
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (g_line[i][j])
    {
        if (g_line[i][j] == '0')
            ft_error("Map Error");
        j++;
    }
    i++;
    j = 0;
    while (g_line[i])
    {
        while (g_line[i][j])
        {
            if ((g_line[i][j] == '0' || g_line[i][j] == 'E' || g_line[i][j] == 'W' || g_line[i][j] == 'N'
             || g_line[i][j] == 'S' || g_line[i][j] == '2' ) && (g_line[i - 1][j] == ' ' || g_line[i + 1][j] == ' ' ||
             g_line[i][j + 1] == ' ' || g_line[i][j - 1] == ' '))
            {
                ft_error("Map Error");
                exit(0);
            }
            j++;
        }
        i++;
        j = 0;
    }

    while (g_line[g_sizeofmap - 1][j])
    {
        if(g_line[g_sizeofmap - 1][j] != '1' && g_line[g_sizeofmap - 1][j] != ' ')
            ft_error("Map Errorr");
            j++;
    }
    ft_single_player();
}
void    ft_secure_map2()
{
    int i;
    int j;
    char *str;
    int len;

    j = 0;
    i = 0;
    while(g_line[i])
    {
        len = g_biglen - ft_strlen(g_line[i]);
        str = malloc(sizeof(char ) * len + 1);
        while(len > 0)
        {
            str[j] = ' ';
            j++;
            len--;
        }
        str[j] = '\0';
        j = 0;
        g_line[i] = ft_strjoin(g_line[i],str);
        i++;
    }
    ft_secure_map3();
}
void    ft_secure_map()
{
    int i;

    i = 0;

    while (g_line[i])
    {    
        g_line[i] = ft_strjoin(" ", g_line[i]);
        g_line[i] = ft_strjoin(g_line[i] ," ");
       i++;
    }
    ft_secure_map2();
    
}