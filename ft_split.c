/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:46:46 by nrossa            #+#    #+#             */
/*   Updated: 2023/02/28 19:08:02 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strings_count(char const *s, char c)
{
	size_t	i;
	size_t	strings_number;

	i = 0;
	strings_number = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			strings_number++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (strings_number);
}

char	*ft_create_strings(char const *s, char c)
{
	char	*dst;
	size_t	i;
	size_t	strings_length;

	strings_length = 0;
	while (s[strings_length] != c && s[strings_length])
		strings_length++;
	dst = malloc(sizeof(char) * (strings_length + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < strings_length)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_split_strings(char const *s, char c, size_t indice)
{
	char	*dst;
	size_t	i;
	size_t	strings_number;

	i = 0;
	strings_number = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (strings_number == indice)
				return (dst = ft_create_strings(s + i, c));
			else
			{
				strings_number++;
				while (s[i] != c)
					i++;
			}
		}
	}
	return (dst = "");
}

void	ft_free_split(char **dst, size_t i)
{
	while (i-- > 0)
		free(dst[i]);
	free(dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	strings_number;

	if (!s)
		return (NULL);
	strings_number = ft_strings_count(s, c);
	dst = malloc(sizeof(char *) * (strings_number + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < strings_number)
	{
		dst[i] = ft_split_strings(s, c, i);
		if (!dst[i])
		{
			ft_free_split(dst, i);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
