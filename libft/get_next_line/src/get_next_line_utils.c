/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:43:59 by graiolo           #+#    #+#             */
/*   Updated: 2022/11/12 15:44:02 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

void	ft_bzero(void *s, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*vect;

	if (nmemb > SIZE_MAX / size)
		return (NULL);
	vect = (void *)malloc(nmemb * size);
	if (!vect)
		return (NULL);
	ft_bzero(vect, nmemb * size);
	return (vect);
}

size_t	ft_strlen(const char *str)
{
	size_t	cur;

	cur = 0;
	while (*(str++))
		cur++;
	return (cur);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_total;
	char	*res;
	int		i;
	int		j;

	i = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len_total + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[len_total] = 0;
	return (res);
}
