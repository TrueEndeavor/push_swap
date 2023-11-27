/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:53:12 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/23 14:41:58 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\t' || \
		c == '\n' || c == '\r' || c == '\v');
}

long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base)
{
	const char	*p = nptr;
	const char	*endp;
	int			is_neg = 0;
	int			overflow = 0;
	unsigned long	n = 0UL;
	
	if (base < 0 || base == 1 || base > 36)
	{
        errno = EINVAL;
        return 0L;
    }
    endp = nptr;
    while (ft_isspace(*p))
        p++;
    if (*p == '+') {
        p++;
    } else if (*p == '-') {
        is_neg = 1, p++;
    }
    while (ft_isdigit(*p) || (base == 16 && ((*p >= 'A' && *p <= 'F') || (*p >= 'a' && *p <= 'f')))) {
        int c;
        if (*p >= 'A')
            c = ((*p - 'A') & (~('a' ^ 'A'))) + 10;
        else if (*p <= '9')
            c = *p - '0';
        else
            break;

        if (c < 0 || c >= base) break;

        endp = ++p;

        if (overflow) {
            if (endptr) continue;
            break;
        }

        if (n > (unsigned long)C_LONG_MAX) {
            overflow = 1;
            printf("Overflow detected: n = %lu\n", n);
            continue;
        }
        n = n * base + c;
    }
    while (ft_isspace(*p))
        p++;
    if (*p != '\0' && endptr) {
        *endptr = (char *)p;
    } else if (endptr) {
        *endptr = (char *)endp;
    }
    if (overflow) {
        errno = ERANGE;
        return ((is_neg) ? C_LONG_MIN : C_LONG_MAX);
    }
    return (long)((is_neg) ? -n : n);
}
