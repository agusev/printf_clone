/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:41:12 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:53:32 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ft_star_width(int *star_width, va_list *arg, t_flags *flags)
{
	int width;

	*star_width = 1;
	width = va_arg(*arg, int);
	if (width < 0)
	{
		width = -width;
		flags->right_padding = 1;
	}
	flags->width = width;
}

char		*handling_width(char **format, t_flags *flags, va_list *arg)
{
	int		star_width;

	star_width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if ((star_width == 1 && ft_isdigit(**format)) || \
			(star_width != 0 && **format == '*'))
			return (NULL);
		if (**format == '*')
			ft_star_width(&star_width, arg, flags);
		if (ft_isdigit(**format))
		{
			star_width = -1;
			flags->width = flags->width * 10 + **format - 48;
		}
		(*format)++;
	}
	return (*format);
}
