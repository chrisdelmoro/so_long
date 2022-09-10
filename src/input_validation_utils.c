/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:31:24 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/09 21:08:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	input_validation(int argc, char *map_path)
{
	char	*substr;

	if (argc != 2)
	{
		ft_printf("Error\nOnly one parameter is accepted! The map file!\n");
		exit(0);
	}
	substr = ft_substr(map_path, ft_strlen(map_path) - 4, 4);
	if (ft_strncmp(".ber", substr, 4))
	{
		ft_printf("Error\nOnly '.ber' files are accepted as map files!\n");
		ft_freethis(&substr, NULL);
		exit(0);
	}
	ft_freethis(&substr, NULL);
}
