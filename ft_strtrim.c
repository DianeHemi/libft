/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:13:00 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/01 13:32:45 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	if ((end = ft_strlen(s1) - 1) > 1)
	{
		while (is_in_set(s1[end], set) && end > 1)
			end--;
	}
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = ft_substr((char *)s1, start, len);
	return (str);
}
