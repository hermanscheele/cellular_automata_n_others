# Cell Automaton

A Conway's Game of Life implementation in Python with a pygame renderer.

## How it works

The simulation runs on an `n x n` grid. Each cell is either alive (`1`) or dead (`0`). On every tick, the standard Game of Life rules are applied:

- A dead cell with exactly **3 live neighbours** becomes alive.
- A live cell with **2 or 3 live neighbours** survives.
- All other cells die or stay dead.

Diagonal neighbours are included in the neighbour count.

## Files

| File | Description |
|------|-------------|
| `cell_auto.py` | Core logic — grid init, rule application |
| `graphics.py` | Interactive pygame renderer |
| `record_gif.py` | Headless recorder — renders 60 frames and saves `demo.gif` |

## Demo

![Cell Automaton Demo](demo.gif)
