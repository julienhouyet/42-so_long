/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <jhouyet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:11:48 by jhouyet           #+#    #+#             */
/*   Updated: 2023/12/04 17:09:35 by jhouyet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void draw_map(void *mlx_ptr, void *win_ptr, t_map map) {

    int x, y;

    for (y = 0; y < map.height; y++) {
        for (x = 0; x < map.width; x++) {
            int color = 0x000000; // Couleur par défaut pour un espace vide

            // Choix des couleurs en fonction des éléments de la carte
            if (map.data[y][x] == '1') {
                color = 0xFFFFFF; // Mur
            } else if (map.data[y][x] == 'P') {
                color = 0x00FF00; // Joueur
            } else if (map.data[y][x] == 'E') {
                color = 0xFF0000; // Sortie
            } else if (map.data[y][x] == 'C') {
                color = 0xFF7000; // Collectible
            }

            // Dessiner la tuile à la position (x, y)
            int px = x * TILE_SIZE;
            int py = y * TILE_SIZE;
            for (int i = 0; i < TILE_SIZE; i++) {
                for (int j = 0; j < TILE_SIZE; j++) {
                    mlx_pixel_put(mlx_ptr, win_ptr, px + i, py + j, color);
                }
            }
        }
    }
}

t_map read_map(const char *file_name) {
    t_map map;
    map.width = 0;
    map.height = 0;

    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char line[MAX_MAP_SIZE];
    
    while (fgets(line, sizeof(line), file)) {
        ft_printf("Ligne lue : %s", line);

        size_t line_length = ft_strlen(line);
        if (line[line_length - 1] == '\n') {
            line_length--;
        }

        if (map.width == 0) {
            map.width = (int)line_length;
        } else if ((size_t)map.width != line_length) {
            perror("La largeur de la carte est incorrecte");
            ft_printf("Taille attendue : %d, Taille lue : %zu\n", map.width, line_length);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < map.width; ++i) {
            map.data[map.height][i] = line[i];
        }
		
        map.height++;

        if (map.height >= MAX_MAP_SIZE) {
            perror("La carte est trop grande");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    return map;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        ft_printf("Usage: %s <nom_du_fichier_ber>\n", argv[0]);
        return EXIT_FAILURE;
    }

    void *mlx_ptr = mlx_init();
    if (!mlx_ptr) {
        perror("Erreur lors de l'initialisation de MLX");
        return EXIT_FAILURE;
    }

    t_map map = read_map(argv[1]);
    ft_printf("\n\nLargeur de la carte : %d\n", map.width);
    ft_printf("Hauteur de la carte : %d\n", map.height);

    void *win_ptr = mlx_new_window(mlx_ptr, TILE_SIZE * map.width, TILE_SIZE * map.height, "Map");
    if (!win_ptr) {
        perror("Erreur lors de la création de la fenêtre");
        return EXIT_FAILURE;
    }

    draw_map(mlx_ptr, win_ptr, map);

    mlx_loop(mlx_ptr);

    // Libérer la mémoire allouée pour la carte
    for (int i = 0; i < map.height; i++) {
        free(map.data[i]);
    }
    free(map.data);

    return EXIT_SUCCESS;
}