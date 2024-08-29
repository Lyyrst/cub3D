/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:34:19 by mrouault          #+#    #+#             */
/*   Updated: 2024/01/04 10:36:38 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/string.h>

void	ft_strcat(char *buffer, char *str)
{
	int	i;
	int	j;

	i = ft_strlen(buffer);
	j = 0;
	while (str[j])
	{
		buffer[i + j] = str[j];
		j++;
	}
	buffer[i + j] = 0;
}
