# Ultimate Tic-Tac-Toe (C++)

Developed a unique C++ console version of "Ultimate Tic-Tac-Toe," enhancing the standard game with nested boards, custom rule logic via operator overloading, and a multi-round structure involving randomness.

This project goes beyond a simple game port, using advanced C++ features as core components of the game's mechanics.

![C++](https://img.shields.io/badge/C%2B%2B-OOP-00599C.svg?logo=cplusplus&logoColor=white)
![Game](https://img.shields.io/badge/Game-Strategy_&_Logic-orange.svg)

---

## 🎮 Core Game Logic

The game is a "best-of-three" match played on a 3x3 `BigBoard`. The twist is that each cell of the `BigBoard` contains its own 3x3 `SmallBoard`.

1.  **Nested Boards:** To play, a user selects a cell on the `BigBoard` (e.g., "top-left") and then a cell on the `SmallBoard` *inside* that cell.
2.  **Claiming Cells:** To win a `SmallBoard`, a player must get three-in-a-row on it.
3.  **Winning a Round:** To win the `BigBoard` (and the round), a player must claim three `SmallBoard`s in a row (horizontally, vertically, or diagonally).
4.  **Multi-Round Match:** The game is played over three rounds. The first player to win two rounds is the overall winner.



---

## 💡 Advanced C++ Features as Game Mechanics

The most unique aspect of this project is the use of **operator overloading** to define custom game rules.

### `operator!` (SmallBoard Tie-Breaker)
* **Purpose:** To deterministically resolve a tie on a `SmallBoard` (i.e., when all 9 cells are full but no one has 3-in-a-row).
* **Mechanic:** The `!` operator is overloaded on the `SmallBoard` class. When a tie is detected, it calculates a "positional sum" for both players (Player 1 and Player 2) based on the cells they hold (e.g., top-left = 1, middle-center = 5, bottom-right = 9). The player with the higher positional sum wins the tie-breaker and claims the `SmallBoard`.

### `operator+` & `operator-` (Round 3 Logic)
* **Purpose:** To determine the winner of the third and final round in a special, non-standard way.
* **Mechanic:** The `+` and `-` operators are overloaded on the `BigBoard` class. The game logic uses these to combine the outcomes of Round 1 and Round 2.
    * If Player 1 wins both Round 1 & 2, the game ends (Best-of-three).
    * If the players split the first two rounds, the "winner" of Round 3 is decided *randomly* based on a predefined combination logic (e.g., P1 wins R1 + P2 wins R2 = Random chance for P1 or P2 in R3).
    * If this random third round *also* results in a draw, another random tie-breaker is used to determine the final match winner.

---

## 🏛️ Code Architecture (OOP)


The system is built on a clean, reusable, and extensible object-oriented design:

* **`Playable` (Interface):** An abstract base class that defines the common interface for any "board," ensuring all board types have functions like `play()` and `print()`.
* **`Board<T>` (Template Class):** A generic template class providing the core logic for any `NxN` grid, used as a base for both `SmallBoard` and `BigBoard`.
* **`SmallBoard` & `BigBoard`:** Concrete classes that inherit from `Playable` and/or `Board<T>`. They contain the specific logic for 3x3 and nested 9x9 play, respectively, and hold their own `BoardStatus`.
* **`Game`:** A high-level controller class that manages the three-round game flow, player turns, and final win/loss/draw state.
* **`Exception`:** A custom exception class for robust error handling, such as catching invalid moves on occupied cells.

---

## 🚀 How to Compile & Run

### Prerequisites
* A C++ compiler (e.g., `g++`, `clang++`, or MSVC)

### Compile
Navigate to the root directory and compile all `.cpp` source files:

```bash
g++ *.cpp -o ultimate_tictactoe
```
*(Note: If you have a `makefile`, you can simply run `make`.)*

### Run
Execute the compiled program from your terminal:

```bash
./ultimate_tictactoe
```
The game will start, and you can play as Player 1 against Player 2 via the console.