/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouault <mrouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:58:14 by mrouault          #+#    #+#             */
/*   Updated: 2024/03/18 15:14:55 by mrouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <stdarg.h>
# include <unistd.h>
# include <libft/string.h>

void		ft_putstr(const char *str);
void		ft_putstr_fd(int fd, const char *str);
void		ft_putendl(const char *str);
void		ft_putchar(char c);

int			ft_vsprintf(char **out, const char *format, va_list args);
int			ft_printf(const char *format, ...);
int			ft_fprintf(int fd, const char *format, ...);
t_string	ft_sprintf(const char *format, ...);

t_string	ft_read_file(t_string path);
char		*get_next_line(int fd);
#endif
