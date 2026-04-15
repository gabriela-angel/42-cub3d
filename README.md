# Cub3D

A 3D raycasting game inspired by the world-famous Wolfenstein 3D, implemented in C using the MiniLibX graphics library.

## Overview

Cub3D is a project that explores ray-casting techniques to create a dynamic 3D view inside a maze. Players navigate through a 2D map representation that gets rendered as a 3D environment, finding their way through walls and open spaces.

## Features

- **Raycasting Engine**: Real-time 3D rendering from 2D map data
- **Texture Mapping**: Wall textures for north, south, east, and west directions
- **Color Configuration**: Customizable floor and ceiling colors
- **Map Validation**: Comprehensive error checking for map integrity
- **Memory Management**: Garbage collection and leak prevention
- **Cross-platform**: Built with MiniLibX for Linux compatibility

## Requirements

- **Operating System**: Linux
- **Compiler**: GCC with C99 support
- **Graphics Library**: MiniLibX (MLX42)
- **Dependencies**:
  - GLFW
  - OpenGL
  - Math library (-lm)
  - Dynamic linking library (-ldl)
  - POSIX threads (-pthread)

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/lhenriqu42/cub3d.git
   cd cub3d
   ```

2. **Build the project**:
   ```bash
   make
   ```

   This will:
   - Compile the libft library
   - Build the MiniLibX graphics library
   - Compile the main Cub3D executable

## Usage

Run the game with a map file:

```bash
./cub3D maps/valid/subject_map.cub
```

### Map Format

Map files (`.cub` extension) contain configuration and layout information:

#### Textures
```
NO ./path/to/north_texture.png
SO ./path/to/south_texture.png
WE ./path/to/west_texture.png
EA ./path/to/east_texture.png
```

#### Colors
```
F 220,100,0        # Floor color (RGB)
C 225,30,0         # Ceiling color (RGB)
```

#### Map Layout
```
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
10111011111111101110000010001
11111111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N111
```

- `1`: Wall
- `0`: Empty space
- `N`/`S`/`E`/`W`: Player starting position and direction

### Controls

*(Implementation may vary - check source code for current controls)*

- **WASD**: Movement
- **Arrow Keys**: Look around
- **ESC**: Exit game

## Project Structure

```
cub3d/
├── include/           # Header files
│   ├── cub3d.h       # Main header
│   ├── error.h       # Error definitions
│   ├── map.h         # Map structures
│   ├── mlx.h         # Graphics definitions
│   └── settings.h    # Configuration constants
├── libs/             # External libraries
│   ├── libft/       # Custom C library
│   └── MLX/         # MiniLibX graphics library
├── maps/            # Map files
│   ├── valid/       # Valid test maps
│   └── invalid/     # Invalid test maps
├── src/             # Source code
│   ├── main.c       # Entry point
│   ├── errors/      # Error handling
│   ├── map/         # Map parsing and validation
│   ├── mlx/         # Graphics initialization
│   └── shared/      # Utility functions
├── tests/           # Test scripts
└── Makefile         # Build configuration
```

## Testing

The project includes comprehensive tests for map validation:

### Python Test Scripts

- `test_maps_simple.py`: Basic map validation tests
- `test_maps.py`: Extended testing with valgrind memory checks

### Running Tests

```bash
# Test all maps
python3 tests/test_maps.py

# Test with valgrind for memory leaks
make valgrind
```

### Sample Maps

- `maps/valid/subject_map.cub`: Basic example map
- `maps/valid/square_map.cub`: Simple square layout
- Various themed maps in the `valid/` directory

## Build Targets

- `make`: Build the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild from scratch
- `make valgrind`: Run with memory leak detection

## Error Handling

The program validates maps for:
- Invalid characters
- Missing textures
- Incorrect color formats
- Map boundary issues
- Player position validation
- Wall integrity (no holes)

## Memory Management

- Uses a custom garbage collector (`ft_gc`)
- Valgrind integration for leak detection
- Proper cleanup of MLX resources

## Authors

- **lhenriqu**
- **g-angel**

## License

This project is part of the 42 curriculum. See project requirements for licensing details.

## Acknowledgments

- Inspired by Wolfenstein 3D
- Built with MiniLibX (MLX42)
- Uses libft for utility functions
