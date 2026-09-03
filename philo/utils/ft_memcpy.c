/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42Bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 22:52:37 by naratass          #+#    #+#             */
/*   Updated: 2026/09/03 23:13:56 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdest = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n--)
		*pdest++ = *psrc++;
	return (dst);
}
