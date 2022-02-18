/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:20:32 by mhong             #+#    #+#             */
/*   Updated: 2022/02/06 17:26:19 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word_make(char *word, char const *s, int end, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
	{
		word[i] = s[end - word_len--];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	cnt_words;

	i = 0;
	cnt_words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt_words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt_words);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**split_func(char **result, char const *s, char c, int cnt)
{
	int		res_idx;
	int		s_idx;
	int		word_len;

	res_idx = 0;
	s_idx = 0;
	word_len = 0;
	while (s[s_idx] && res_idx < cnt)
	{
		while (s[s_idx] && s[s_idx] == c)
			s_idx++;
		while (s[s_idx] && s[s_idx] != c)
		{
			s_idx++;
			word_len++;
		}
		result[res_idx] = (char *)malloc(word_len + 1);
		if (!result[res_idx])
			return (ft_malloc_error(result));
		word_make(result[res_idx], s, s_idx, word_len);
		word_len = 0;
		res_idx++;
	}
	result[res_idx] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		cnt_word;
	char	**res;

	if (s == NULL)
		return (NULL);
	cnt_word = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!res)
		return (NULL);
	split_func(res, s, c, cnt_word);
	return (res);
}
