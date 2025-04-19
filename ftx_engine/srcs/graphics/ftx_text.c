/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftx_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:02:26 by chugon            #+#    #+#             */
/*   Updated: 2025/04/18 16:29:11 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ftx_core.h"
#include "ftx_error.h"

t_engine	*ftx_internal__engine(void);
char		*ftx_internal__parse_args(const char *f, va_list *l);
char		*ftx_internal__strdup(const char *s);
int			ftx_internal__error(int e);
int			ftx_internal__text_renderer(void *p);
int			ftx_internal__show(void *p, t_renderer r, t_renderobject **l);
int			ftx_internal__hide(void *p, t_renderobject **l);
int			ftx_internal__setzindex(void *p, int z, t_renderobject **l);

void		*ftx_internal__allocate(size_t s, t_deleter d,
				t_allocator a, void *p);
void		ftx_internal__text_deleter(void *p);
int			ftx_internal__text_allocator(void *p, void *l);

t_text	*ftx_text(char *str, int x, int y, t_color color)
{
	t_text	*text;

	if (str == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR), FTX_NULLPTR);
	text = ftx_internal__allocate(sizeof(t_text),
			&ftx_internal__text_deleter,
			&ftx_internal__text_allocator,
			str);
	if (text == FTX_NULLPTR)
		return (FTX_NULLPTR);
	text->x = x;
	text->y = y;
	text->color = color;
	return (text);
}

int	ftx_text_format(t_text *text, const char *format, ...)
{
	va_list	list;
	char	*str;

	if (text == FTX_NULLPTR || format == FTX_NULLPTR)
		return (ftx_internal__error(FTX_ERROR_NULLPTR));
	va_start(list, format);
	str = ftx_internal__parse_args(format, &list);
	va_end(list);
	free(text->_internal.str);
	text->_internal.str = ftx_internal__strdup(str);
	return (FTX_SUCCESS);
}

int	ftx_text_show(t_text *text)
{
	return (ftx_internal__show(text, &ftx_internal__text_renderer,
			&(ftx_internal__engine()->rendertexts)));
}

int	ftx_text_hide(t_text *text)
{
	return (ftx_internal__hide(text,
			&(ftx_internal__engine()->rendertexts)));
}

int	ftx_text_setzindex(t_text *text, int z)
{
	return (ftx_internal__setzindex(text, z,
			&(ftx_internal__engine()->rendertexts)));
}
