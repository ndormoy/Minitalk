/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:02:54 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/22 19:09:01 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_wlen(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

int	count_words(char const *s, char c)
{
	unsigned int	len;
	unsigned int	words;

	words = 0;
	len = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len = count_wlen(s, c);
		s += len;
		if (len != 0)
			words++;
	}
	return (words);
}

char	*w_copy(char const *s, unsigned int w_len)
{
	unsigned int	i;
	char			*ret;

	if (w_len == 0)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(char) * (w_len + 1));
	if (!ret)
		return (NULL);
	while (i < w_len)
	{
		ret[i] = *s;
		i++;
		s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int				words;
	unsigned int	w_len;
	int				i;
	char			**strs;

	if (!s)
		return (NULL);
	i = -1;
	words = count_words(s, c);
	strs = ft_calloc(words + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	while (i++ < words)
	{
		while (*s == c && *s)
			s++;
		w_len = count_wlen(s, c);
		strs[i] = w_copy(s, w_len);
		s += w_len;
	}
	return (strs);
}
