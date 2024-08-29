/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:58:29 by mrouault          #+#    #+#             */
/*   Updated: 2024/05/01 14:58:04 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCONV_H
# define STRCONV_H

# include <libft/string.h>
# include <stdint.h>

# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define DEC_BASE "0123456789"

double		ft_atof(const char *str);
double		hex_float_to_d(const char *str);
int			ft_atoi(const char *str);
int64_t		ft_safe_atol(const char *str,
				bool *error, int64_t min, int64_t max);
t_string	ft_itoa(int n);
t_string	ft_itoa_base(int n, const char *base, int radix);
t_string	ft_utoa(uint64_t n);
t_string	ft_utoa_base(uint64_t n, const char *base, int radix);
t_string	ft_ftoa(double f);

#endif
