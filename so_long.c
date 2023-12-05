/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/05 12:20:32 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		ft_printf("Utilisation: %s <nom_du_fichier_ber>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = ft_strlen(argv[1]);
		if (!(i >= 4 && argv[1][i - 4] == '.' && \
		argv[1][i - 3] == 'b' && argv[1][i - 2] == 'e' && \
		argv[1][i - 1] == 'r'))
		{
			ft_printf("Léxtension du fichier de la map doit être .ber\n");
			exit(EXIT_FAILURE);
		}
	}
}

int	main(int argc, char **argv)
{
	check_argv(argc, argv);
	ft_printf("Coucou toi");
}
