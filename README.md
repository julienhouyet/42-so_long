# 42-so_long

![42-so_long](https://socialify.git.ci/julienhouyet/42-so_long/image?language=1&logo=https%3A%2F%2Fgithub.com%2Fayogun%2F42-project-badges%2Fblob%2Fmain%2Fbadges%2Fso_longm.png%3Fraw%3Dtrue&name=1&owner=1&pattern=Circuit%20Board&theme=Auto)

# Introduction

This project is a tiny 2D game I developed during my studies at 42. The aim was to familiarize myself with sprites, textures and a few basic elements. I was inspired by Pokemon Red.

This project is being developed with the minilibx from 42.

At [42 School](https://github.com/42School), almost every project must be written in accordance to the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf), the school's coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.

## :zap: Usage

###  :electric_plug: Installation

To install the project, clone this repository :

```
$ git clone git@github.com:julienhouyet/42-so_long.git
```

To compile the game, run this command :

```
$ make
```

###  :package: Commands

After compiling the project, the executable file with the name so_long will be created, to run the game call the executable passing the map as an argument:

Example:

```
$ ./so_long assets/maps/01.ber
```

```
$ ./so_long assets/maps/03.ber
```

To wipes all object files :

```
$ make clean
```

To delete so_long and all object files

```
$ make fclean
```

###  :notebook: More

You can create your own map.

Your map must be a .ber file. 

It must be square or rectangular, and surrounded by 1 (wall). 

You must use 1 P (player), 1 E (exit), and at least 1 C (item).

You can use the following characters:

Char | Sprite
--- | --- 
0 | Floor
1 | Wall
P | Player
E | Exit
C | Item

##  :page_facing_up: Resources
 
[Minilibx Docs](https://harm-smits.github.io/42docs/libs/minilibx)

##  :camera: Gallery

<p align="center">
  <img src="https://i.ibb.co/FYQKSLn/Screenshot-2023-12-21-at-11-50-33.png">
</p>
