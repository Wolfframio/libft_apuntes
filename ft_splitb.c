/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:16:23 by imontero          #+#    #+#             */
/*   Updated: 2023/05/13 19:16:23 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	palabras(char const *s, char c)
{
	unsigned int	p;

	p = 0;
	while (*(s++))
		if ((*s == 0 || *s == c) && *(s - 1) != c)
			p++;
	return (p);
}

static size_t	ft_wlen(const char *s, char c)
{
	int	l;

	l = 0;
	while (s[l] && s[l] != c)
		l++;
	return (l);
}

static char	**liberate(char ***f, unsigned int p)
{
	unsigned int	i;
	char			**sl;

	i = 0;
	sl = *f;
	while (i < p && sl[i])
	{
		free(sl[i]);
		i++;
	}
	free(sl);
	return (NULL);
}

char	**ft_splitok(char const *s, char c)
{
	char			**sl;
	unsigned int	i;
	unsigned int	p;

	sl = malloc(sizeof(char *) * (palabras(s, c) + 1));
	if (!sl)
		return (0);
	i = 0;
	p = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		sl[p] = ft_substr(s, i, ft_wlen(s + i, c));
		if (!sl[p])
			return (liberate(&sl, p));
		p++;
		i = i + ft_wlen(s + i, c);
		while (s[i] == c && s[i])
			i++;
	}
	sl[p] = 0;
	return (sl);
}






char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(1 + len * sizeof(char));
	if (!sub)
		return (NULL);
	sub[len] = '\0';
	while (s[start] && len > 0)
	{
		len--;
		sub[len] = s[start + len];
	}
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}


static void	ft_freeall(char **tab, int k)
{
	while (k >= 0)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
}

static int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

static char	**ft_strings(char **tab, char *s, char c)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			start = 0;
		if (i == 0 && s[i] == c)
			i++;
		if (s[i - 1] == c && s[i] != c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[j] = ft_substr(s, start, i - start + 1);
			if (!tab[j])
				ft_freeall(tab, j - 1);
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;

	count = ft_count((char *)s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = '\0';
	return (ft_strings(tab, (char *)s, c));
}

int	main(void)
{
	char	*str;
	char	**array;
	char	**arrayok;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = ' ';
	str = " caguen sus muelas ";
	array = ft_split(str, c);
	while (array[i])
	{
		//write (1, "no", 2);
		write (1, array[i], 20);
		write (1, "\n", 1);
		//printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);

	//printf("\n");
	write (1, "\n", 1);

	arrayok = ft_splitok(str, c);
	while (arrayok[j])
	{
		//write (1, "ok", 2);
		write (1, arrayok[j], 20);
		write (1, "\n", 1);
		//printf("%s\n", arrayok[j]);
		free(arrayok[j]);
		j++;
	}
	free(arrayok);
	return (0);
}