/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:13 by mrouault          #+#    #+#             */
/*   Updated: 2024/03/18 15:17:46 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/memory.h>
#include <libft/string.h>

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	new_str = ft_calloc(ft_strlen(str) + 1, 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}
