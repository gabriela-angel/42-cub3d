/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:04:27 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/09 19:51:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_increment_if_ansi_code(char *str, size_t i)
{
	size_t	new_i;

	new_i = 0;
	while (1)
	{
		while (i && str[new_i] != '\033')
		{
			new_i++;
			i--;
		}
		if (str[new_i] == '\033' && str[new_i + 1] == '[')
		{
			while (str[new_i] && str[new_i] != 'm')
				new_i++;
			if (str[new_i] == 'm')
				new_i++;
		}
		else
			break ;
	}
	return (new_i);
}

char	*ft_iputcolor(char *str, size_t i, const char *color)
{
	char	*colored_char;
	char	*left_str;
	char	*right_str;
	char	*tmp;
	char	*result;

	i = ft_increment_if_ansi_code(str, i);
	left_str = ft_substr(str, 0, i);
	right_str = ft_substr(str + i + 1, 0, ft_strlen(str) - i - 1);
	tmp = ft_substr(str + i, 0, 1);
	colored_char = ft_strjoin(color, tmp);
	ft_free(tmp);
	colored_char = ft_strjoin_with_free(colored_char, C_RST);
	result = ft_strjoin_with_free(left_str, colored_char);
	ft_free(colored_char);
	result = ft_strjoin_with_free(result, right_str);
	ft_free(right_str);
	return (result);
}
