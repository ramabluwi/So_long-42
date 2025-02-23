# so_long-42

## Overview
The **so_long** project is a 2D game where the player controls **Sonic**, navigating through a structured map to collect **gold rings**. The objective is to gather all rings and reach the exit to successfully complete the level.

## Features
- **Playable Character (Sonic)**: Controlled using arrow keys for movement.
- **Collectable Items (Rings)**: Essential for unlocking the exit.
- **Exit Mechanism**: Becomes accessible only after collecting all rings.

## Installation
To set up and run **so_long**, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/ramabluwi/so_long-42.git
    ```

2. Navigate to the project directory:
    ```bash
    cd so_long-42
    ```

3. Compile the project:
    ```bash
    make
    ```

## Gameplay Instructions
- **Controls**:
    - Use the **arrow keys** to navigate Sonic across the map.
    - Collect rings by passing over them.
    - Reach the exit once all rings are collected to complete the level
- **Objective**: Successfully collect all rings and exit the level.


## Requirements
- **MinilibX**: A lightweight graphics library required for rendering the game. Install it by following the official [MinilibX repository](https://github.com/42Paris/minilibx) instructions.

## Troubleshooting
- Ensure **MinilibX** is correctly installed and accessible.
- On macOS, compile with the appropriate framework flags:
    ```bash
    -lmlx -framework OpenGL -framework AppKit
    ```

## Acknowledgments
- Inspired by classic 2D platformers, particularly Sonic the Hedgehog.
- Special thanks to **42 School** for providing the foundation and resources for this project.


