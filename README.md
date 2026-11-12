# Slide Puzzle Game

A 4x4 sliding tile puzzle with one empty space. The board starts shuffled, and you win by sliding the tiles back into order (1-15) before time runs out.

Made by Melani Gunettige and Osiris Xiao.


<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1452 1150" width="1452" height="1150" font-family="Arial, Helvetica, sans-serif">
  <defs>
    <linearGradient id="title" x1="0" x2="1" y1="0" y2="0">
      <stop offset="0" stop-color="#0a246a"/>
      <stop offset="1" stop-color="#a6caf0"/>
    </linearGradient>
  </defs>

  <!-- window background -->
  <rect width="1452" height="1150" fill="#44969a"/>

  <!-- title bar -->
  <rect width="1452" height="48" fill="url(#title)"/>
  <circle cx="24" cy="26" r="11" fill="#f2c230"/>
  <rect x="19" y="34" width="10" height="8" rx="1" fill="#c9971c"/>
  <text x="46" y="35" font-size="24" font-weight="bold" fill="#ffffff">Slide Puzzle</text>
  <g fill="#d4d0c8" stroke="#ffffff" stroke-width="2">
    <rect x="1334" y="12" width="40" height="30"/>
    <rect x="1378" y="12" width="40" height="30"/>
    <rect x="1420" y="12" width="28" height="30"/>
  </g>
  <rect x="1344" y="34" width="16" height="4" fill="#000"/>
  <rect x="1388" y="18" width="20" height="16" fill="none" stroke="#000" stroke-width="3"/>
  <path d="M1427 20 L1441 34 M1441 20 L1427 34" stroke="#000" stroke-width="4"/>

  <!-- status text -->
  <text x="12" y="98" font-size="46" font-weight="bold" fill="#ffffff">Generating new puzzle...</text>

  <!-- board border -->
  <rect x="343" y="213" width="754" height="762" rx="6" fill="#1f4fe0"/>

  <!-- tiles -->
  <g fill="#62cf40">
    <rect x="352" y="222" width="736" height="744"/>
  </g>
  <!-- empty tile (row 3, col 2) -->
  <rect x="536" y="590" width="184" height="184" fill="#44969a"/>

  <!-- tile seams -->
  <g stroke="#58c038" stroke-width="2">
    <path d="M536 222V590M720 222V966M904 222V966M536 774V966"/>
    <path d="M352 406H1088M352 590H536M720 590H1088M352 774H536M720 774H1088"/>
    <path d="M536 590V774" stroke="none"/>
  </g>

  <!-- numbers -->
  <g font-size="48" font-weight="bold" fill="#ffffff" text-anchor="middle">
    <text x="444" y="332">1</text>
    <text x="628" y="332">7</text>
    <text x="812" y="332">2</text>
    <text x="996" y="332">3</text>

    <text x="444" y="516">5</text>
    <text x="628" y="516">14</text>
    <text x="812" y="516">6</text>
    <text x="996" y="516">8</text>

    <text x="444" y="700">9</text>
    <text x="812" y="700">12</text>
    <text x="996" y="700">4</text>

    <text x="444" y="884">13</text>
    <text x="628" y="884">10</text>
    <text x="812" y="884">15</text>
    <text x="996" y="884">11</text>
  </g>

  <!-- buttons -->
  <g fill="#62cf40">
    <rect x="1175" y="938" width="130" height="48"/>
    <rect x="1175" y="1005" width="240" height="48"/>
    <rect x="1175" y="1073" width="125" height="48"/>
  </g>
  <g font-size="42" font-weight="bold" fill="#ffffff">
    <text x="1178" y="977">Reset</text>
    <text x="1178" y="1044">New Game</text>
    <text x="1178" y="1112">Solve</text>
  </g>
</svg>

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
