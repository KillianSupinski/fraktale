/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 07:42:20 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/12 15:38:53 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *str, int nb)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (nb + 1));
	if (!cpy)
		return (NULL);
	while (i < nb)
	{
		cpy[i] = *str;
		str++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	ft_countword(const char *str, char c)
{
	int	i;
	int	nb;
	int	count;

	i = 0;
	nb = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (count == 1)
			{
				count = 0;
				nb++;
			}
		}
		else
			count = 1;
		i++;
	}
	if (count == 1)
		nb++;
	return (nb);
}

static char	**ft_fill(char *str, char **tab, char c)
{
	int		count;
	int		i;
	char	*start;

	count = 0;
	i = -1;
	start = str;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (count == 1)
			{
				tab[++i] = ft_strndup(start, str - start);
				count = 0;
			}
			start = str + 1;
		}
		else if (*str != '\0')
			count = 1;
		str++;
	}
	if (count == 1)
		tab[++i] = ft_strndup(start, str - start);
	return ((tab[++i] = NULL), tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	char	*str;
	int		nb;

	str = (char *)s;
	nb = ft_countword(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	if (nb == 0)
		tab[0] = NULL;
	else
		tab = ft_fill(str, tab, c);
	return (tab);
}
/*
int	main(void)
{
	char	**tab;
	int		i;
	char	c;

	c = ' ';
	tab = ft_split(" le", ' ');
	i = 0;
	printf("tab1:\n");
	while (tab[i])
	{
		printf("%s", tab[i]);
		printf("\n");
		i++;
	}
}*/
