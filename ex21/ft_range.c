/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:10:21 by ertrigna          #+#    #+#             */
/*   Updated: 2024/11/04 14:24:18 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	size;

	size = max - min;
	if (!size)
		return (NULL);
	range = malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	if (min >= max)
		return (NULL);
	i = 0;
	while (i < size)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
