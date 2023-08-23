# 15-Puzzle-cli

Welcome to the 15 Puzzle Command-Line Game repository! This project implements the classic 15 Puzzle game in C++. The game challenges players to rearrange the numbered tiles to form the correct numerical order.

![Screenshot 2023-08-23 180209](https://github.com/Edveika/15-Puzzle-cli/assets/113787144/63da464a-ab7b-48bd-af40-98a52c604dfa)

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [How to Play](#how-to-play)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The 15 Puzzle, also known as the "Fifteen Game," is a sliding puzzle where players must move tiles into an empty space, one move at a time, to arrange the tiles in the correct numerical sequence.

## Features

- Text-based command-line interface for gameplay.
- Modular code structure for easy expansion and maintenance.
- Smart pointer usage for memory management.
- Basic error handling and exception throwing.
- Basic input handling for tile movement.
- Time tracking using a simple Timer class.
- Victory check to determine when the puzzle is solved.

## Getting Started

To get started with the 15 Puzzle game, follow these steps:

1. Clone the repository to your local machine using the following command:
git clone https://github.com/YourUsername/15-puzzle-cli.git

2. Compile it using Visual Studio

NOTE: this game was coded on Windows, console clearing will not work on linux, you have to change this [line](https://github.com/Edveika/15-Puzzle-cli/blob/f4f08b4a525bd3acef7d3a1049fb8c5eebc60f39/15%20Puzzle-cli/Src/Game/Game.cpp#L38C2-L38C16) to clear instead of cls

## How to Play

- Use the keyboard keys `w`, `a`, `s`, and `d` to slide tiles in the up, left, down, and right directions, respectively.
- The goal is to arrange the tiles in ascending numerical order, with the empty space at the bottom-right corner.

## Contributing

Contributions are not actively sought for this project as it serves as a personal learning project. However, feel free to fork the repository and experiment with your own modifications.

## License

This project is licensed under the GPL v2 [LICENSE](LICENSE).

_Enjoy the challenge of solving the 15 Puzzle!_
