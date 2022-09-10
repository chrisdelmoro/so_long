/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_3_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:41:03 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/10 12:43:18 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	get_player_position(t_game *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.lines[i])
	{
		while (data->map.lines[i][j])
		{
			if (data->map.lines[i][j] == 'P')
			{
				data->map.player_line = i;
				data->map.player_collum = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
