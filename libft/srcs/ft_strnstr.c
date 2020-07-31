/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 02:20:47 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/23 01:21:41 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	if (str2[0] == '\0')
		return ((char*)str1);
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			k = i;
			while ((str1[k] == str2[k - i]) && str2[k - i])
				k++;
			if (k > len)
				return (NULL);
			if (str2[k - i] == '\0')
				return ((char*)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
