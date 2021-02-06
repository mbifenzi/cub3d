/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:56:40 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/02/02 16:14:45 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t		ft_numwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			count++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char			**ft_free(char **str, int num)
{
	while (--num)
		free(&str[num]);
	free(str);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	num;
	size_t	start;
	size_t	len;
	char	**str;

	if (s == 0)
		return (0);
	len = 0;
	i = 0;
	num = ft_numwords(s, c) + 1;
	if (!(str = (char **)malloc(sizeof(char *) * (num))))
		return (NULL);
	while (i < num - 1)
	{
		while (s[len] == c && s[len])
			len++;
		start = len;
		while (s[len] != c && s[len])
			len++;
		if (!(str[i++] = ft_substr(s, start, (len - start))))
			return (ft_free(str, num));
	}
	str[i] = 0;
	return (str);
}
