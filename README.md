# Stack Matching Game

## Overview
This is a simple console-based game where you have four stacks labeled 1 to 4. The objective is to rearrange the symbols (`O`, `X`, `#`) between these stacks so that each stack contains identical symbols. You win the game when all stacks contain the same symbol.

## How to Play
- The game starts with symbols (`O`, `X`, `#`) randomly distributed across the four stacks.
- Your goal is to move the symbols between the stacks until each stack contains only one type of symbol.
- The game ends when all four stacks are uniform, meaning that every symbol in a stack is the same.

## Game Rules
- Each stack can hold a maximum of 4 symbols.
- You can only move the top symbol from one stack to another.
- A stack that already contains 4 symbols cannot accept any more symbols.
- You win the game when all four stacks either contain identical symbols or are empty.

## How to Run
1. Compile the game using a C++ compiler.
2. Run the executable.
3. Follow the on-screen prompts to move symbols between stacks.
4. Keep rearranging until all stacks are uniform.

## Code Structure
- **AllElementsSameFunctor**: A functor used to check if all elements in a stack are identical.
- **printStack**: A function to display the current contents of a stack.
- **main**: The main function where the game logic is implemented, including the random distribution of symbols and the game loop.

## Example Gameplay
```text
Stack 1:
| O |
| # |
| X |
| O |
|___|

Stack 2:
| X |
| O |
| # |
| X |
|___|

...

Enter Source Stack: 1
Enter Destination Stack: 2

...

You Won the Game!

## How to Clone, Compile, and Run

### Prerequisites
- A C++ compiler (e.g., `g++`, `clang++`).
- `git` installed on your system.

### Step 1: Clone the Repository
To clone the repository, open a terminal and run the following command:

```bash
git clone https://github.com/yourusername/your-repository-name.git

