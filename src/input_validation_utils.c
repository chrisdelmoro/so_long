/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:31:24 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/30 19:05:09 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	input_validation(int argc, char *map_path)
{
	if (argc != 2)
	{
		ft_printf("Only one parameter is accepted! The map file!\n");
		return (0);
	}
	if (ft_strncmp(".ber", ft_substr(map_path, ft_strlen(map_path) - 4, 4), 4))
	{
		ft_printf("Only '.ber' files are accepted as map files!\n");
		return (0);
	}
	return (1);
}
