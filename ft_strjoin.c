/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:57:13 by proso             #+#    #+#             */
/*   Updated: 2016/11/26 16:39:10 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int		ft_duo_strlen(char const *s1, char const *s2)
{
	unsigned int		i;

	i = 0;
	while (*s1 != '\0')
	{
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		s2++;
		i++;
	}
	return (i - 1);
}

char					*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(char) * ft_duo_strlen(s1, s2));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
