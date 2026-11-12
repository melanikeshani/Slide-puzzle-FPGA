# Slide Puzzle Game

A 4x4 sliding tile puzzle with one empty space. The board starts shuffled, and you win by sliding the tiles back into order (1-15) before time runs out.

Made by Melani Gunettige and Osiris Xiao.

## How it works

- Move the selector with the arrow keys and press Enter to slide a tile into the empty space. Only the tiles right next to the empty space can move.
- The selected tile is shown in red, so you can always see where you are.
- Every time a tile lands in its correct spot, you get a point and a sound effect plays.
- A row of trees on the screen fades away as time runs out, so you can tell how fast you're going at a glance.
- The time left shows on the HEX display. When the game ends, the HEX display shows your score instead.
- Solve it for a "won game" screen, or run out of time and get "Game over" (with a sound too).

## What we used

- VGA for the board, tiles, numbers, trees and game over screens
- PS/2 keyboard for input
- Timer interrupts for the countdown
- HEX displays for time and score
- Audio output for sound effects

## Who did what

| Part | Who |
| --- | --- |
| Keyboard input, current position, bounds check | Melani |
| Tile sliding logic (swap with the empty space) | Melani |
| Audio output, timer interrupts, HEX display | Melani |
| Drawing digits 1-15, win check, background | Osiris |
| Integration | Both |

## Colours

Green background, blue puzzle, yellow border, white numbers, red for the selected tile.
