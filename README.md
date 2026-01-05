# 🧱 cub3D

A small 3D ray‑caster in C inspired by Wolfenstein 3D, built with MiniLibX as part of the 42 school curriculum.

## 🎮 Features
- ⛓️ Raycasting engine with textured walls
- 🧭 Player movement and camera rotation (W/A/S/D + arrows)
- 🎨 Floor and ceiling colors parsed from `.cub` map files
- 🗺️ Map parsing with validation and flood‑fill closure checks
- 📦 Bonus version with extra features (doors, minimap, mouse, etc.)

## 🚀 Build

Requirements:
- 🐧 Linux + X11
- 🧰 `make`, `cc` (or a compatible C compiler)
- 📚 MiniLibX in `includes/mlx` (as expected by the Makefile)

Build the mandatory part:
```sh
make
```

Build the bonus part:
```sh
make bonus
```

Clean objects / binaries:
```sh
make clean   # remove objects
make fclean  # clean + remove binaries
make re      # full rebuild
```

## ▶️ Run

Mandatory:
```sh
./cub3D maps/subject_map.cub
```

Bonus:
```sh
./cub3D_bonus maps/door_cheese_maze.cub
```

The executable expects a single `.cub` map file as argument. The map file defines textures, colors and the map layout.

## ⌨️ Controls

- `W` / `S` – Move forward / backward
- `A` / `D` – Strafe left / right
- `←` / `→` – Rotate view left / right
- `Esc` – Quit
- (Bonus) Shift / Lock keys – Toggle mouse look lock (see bonus key handling)

## 📂 Project Structure

- `cub3d.c` – Entry point, argument validation, main loop setup
- `includes/cub3d.h` – Main header, structs and function prototypes
- `events/` – Keyboard handling, closing window, cleanup
- `game/` – Game loop, player initialization, MiniLibX setup, collision (`is_wall`)
- `parser/` – File parsing, textures/colors, map loading, flood fill & map checks
- `render/` – Raycasting, wall drawing, textures, frame rendering
- `textures/` & `texture/` – Texture loading helpers and texture assets
- `maps/` – Sample `.cub` maps
- `utils/` – Error handling, freeing helpers, small utilities
- `libft/` – Custom C standard‑like library used by the project
- `bonus/` – Bonus version: doors, minimap, mouse handling, updated rendering, etc.

## 📝 Map File Format (quick overview)

A `.cub` file (see `maps/subject_map.cub`) typically contains:
- 4 wall textures: `NO`, `SO`, `WE`, `EA` pointing to `.xpm` files
- Floor (`F r,g,b`) and ceiling (`C r,g,b`) colors
- Followed by a 2D map using `1` (wall), `0` (empty), spaces, and a player start (`N`, `S`, `E`, `W`)

Example snippet:
```text
NO texture/simonkraft/grey_stone.xpm
SO texture/simonkraft/purple_stone.xpm
WE texture/simonkraft/red_brick.xpm
EA texture/simonkraft/wood.xpm

F 220,100,0
C 225,30,0

111111
1000N1
111111
```

## 📜 License

This project is part of the 42 school curriculum; reuse according to your school rules and your own judgement. 🎓
