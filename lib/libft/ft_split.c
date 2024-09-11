/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:39:11 by mabril            #+#    #+#             */
/*   Updated: 2024/09/09 19:32:05 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	size_t	i;
	char	*ptr_str;
	size_t	count;

	count = 0;
	i = 0;
	ptr_str = (char *)str;
	if (ptr_str[i] == '\0')
		return (count);
	while (ptr_str[i])
	{
		while (ptr_str[i] == c)
			i++;
		if (ptr_str[i])
			count++;
		while (ptr_str[i] != c && ptr_str[i])
			i++;
	}
	return (count);
}

static size_t	ft_get_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0' && (*(s + i) != c))
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i-- > 0)
		free(*(array + i));
	free(array);
}

static char	**ft_1split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) != '\0' && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, ft_get_words_len((s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) != '\0' && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words_count;

	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!array)
		return (NULL);
	array = ft_1split(s, c, array, words_count);
	return (array);
}
