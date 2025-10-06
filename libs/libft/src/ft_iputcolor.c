/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:04:27 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/10/06 18:27:57 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color_info	ft_iputcolor(char *str, size_t i, const char *color)
{
	char			*colored_char;
	char			*left_str;
	char			*right_str;
	char			*tmp;
	t_color_info	color_info;

	left_str = ft_substr(str, 0, i);
	right_str = ft_substr(str + i + 1, 0, ft_strlen(str) - i - 1);
	tmp = ft_substr(str + i, 0, 1);
	colored_char = ft_strjoin(color, tmp);
	free(tmp);
	colored_char = ft_strjoin_with_free(colored_char, C_RST);
	color_info.result = ft_strjoin_with_free(left_str, colored_char);
	color_info.colored_part_len = ft_strlen(colored_char);
	free(colored_char);
	color_info.result = ft_strjoin_with_free(color_info.result, right_str);
	free(right_str);
	color_info.str_len = ft_strlen(color_info.result);
	return (color_info);
}
