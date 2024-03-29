/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:57 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 14:39:58 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			hashtag;
	int			right_padding;
	int			zero_padding;
	int			width;
	int			precision;
	int			precision_exist;
	int			null_char;
	int			length;
	char		conversion;
	char		*format;
}				t_flags;

char			*start_conversion(t_flags *flags, va_list *arg, int *length, \
					char **str);
char			*conversion_c(va_list *arg, int *length, t_flags *flags);
char			*conversion_wide_c(va_list *arg, int *length, t_flags *flags);
char			*conversion_wide_s(va_list *arg);
char			*conversion_s(va_list *arg);
char			*conversion_b(va_list *arg, t_flags *flags);
char			*conversion_p(va_list *arg);
char			*conversion_d_i(va_list *arg, t_flags *flags);
char			*conversion_o_cap_o(va_list *arg, t_flags *flags);
char			*conversion_x_cap_x(va_list *arg, t_flags *flags);
char			*conversion_u_cap_d_cap_u(va_list *arg, t_flags *flags);
char			*conversion_f(va_list *args, t_flags *f);
int				parse_flags(char **format, t_flags *flags, \
					va_list *arg);
char			*handling_flags(char **format, t_flags *flags);
char			*handling_format(char **format, t_flags *flags);
char			*handling_precision(char **format, t_flags *flags, \
					va_list *arg);
char			*handling_width(char **format, t_flags *flags, va_list *arg);
int				regular_character_string(char **next, t_flags *flags, \
					va_list *arg);
int				wide_character_string(char **next, t_flags *flags, \
					va_list *arg);
char			*adding_width(t_flags *flags, char *str);
int				adding_width_wide(t_flags *flags, int length_str);
char			*adding_width_null_char(t_flags *flags, char *answer, \
					int *length, char **str);
char			*adding_plus(t_flags *flags, char *str);
char			*adding_space(t_flags *flags, char *str);
char			*adding_minus(t_flags *flags, char *str);
char			*adding_precision_string(t_flags *flags, char *str);
char			*adding_precision_number(t_flags *flags, char *str);
int				ft_printf(const char *format, ...);
int				printing_string_wide(wchar_t *str);
char			*ft_itoa_intmax(long long value);
char			*ft_itoa_unsigned(uintmax_t value);
char			*ft_itoa_base_unsigned(uintmax_t value, int base);
char			*filler(int c, int len);

#endif
