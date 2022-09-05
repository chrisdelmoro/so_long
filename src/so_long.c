/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:58:04 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/04 19:08:26 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	t_map	map;

	if (input_validation(argc, argv[1]))
	{
		map_validation(&map, argv[1]);
		/* i = 0;
		while (map.lines[i])
		{
			ft_printf("%d - %s\n", i + 1, map.lines[i]);
			i++;
		} */
		flush_map(&map);
	}
	return (0);
}
