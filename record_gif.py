import pygame as pg
import numpy as np
from PIL import Image
from cell_auto import init_grid, add_ones, gen_random, apply_rule

pg.init()
screen_size = 600
screen = pg.display.set_mode((screen_size, screen_size))

GREY  = (200, 200, 200)
RED   = (225, 0, 0)
WHITE = (255, 255, 255)

n = 80
grid = init_grid(n)
cord = gen_random(n, 1000)
add_ones(grid, cord)

border = 1
cell_size = (screen_size - border * n) / n

frames = []
num_frames = 60
scale = 2  # scale down for smaller gif

for _ in range(num_frames):
    screen.fill(WHITE)
    for i in range(n):
        for j in range(n):
            x = j * (cell_size + border)
            y = i * (cell_size + border)
            color = RED if grid[i][j] == 1 else GREY
            pg.draw.rect(screen, color, (x, y, cell_size, cell_size))

    apply_rule(grid)
    pg.display.flip()

    raw = pg.surfarray.array3d(screen)
    # surfarray gives (width, height, 3), PIL wants (height, width, 3)
    raw = np.transpose(raw, (1, 0, 2))
    img = Image.fromarray(raw)
    img = img.resize((screen_size // scale, screen_size // scale), Image.NEAREST)
    frames.append(img)

pg.quit()

frames[0].save(
    "demo.gif",
    save_all=True,
    append_images=frames[1:],
    loop=0,
    duration=50,  # ms per frame → ~20 fps
    optimize=False,
)
print("Saved demo.gif")
