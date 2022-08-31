/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:04:37 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/30 21:24:48 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	map_validation(char *map_path)
{
	int		fd;
	//char	*lines[8];
	char	*lreturn;
	size_t	i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error! Failed to load map file!\n");
	}
	i = 0;
	while (get_next_line(fd))
		i++;
	ft_printf("Line count: %d\n", i);
	i = 0;
	lreturn = get_next_line(fd);
	while (lreturn)
	{
		ft_printf("Returned Line: %s", lreturn);
		//lines[i] = lreturn;
		lreturn = get_next_line(fd);
		i++;
	}
	close(fd);
}