import pygame as pg
from cell_auto import init_grid, add_ones, gen_random, apply_rule


pg.init()
clock = pg.time.Clock()
screen_size = 600
screen = pg.display.set_mode((screen_size, screen_size))

YELLOW = (255, 255, 0)
RED = (225, 0, 0)
WHITE  = (255, 255, 255)
GREY   = (200, 200, 200)
PINK   = (255, 105, 180)


n = 80
# cord = [(1,2), (2,3), (4,4), (3,3), (0,0), (4,0), (1,3)]
grid = init_grid(n)
count = 1000
cord = gen_random(n, count)
add_ones(grid, cord)

border = 1
cell_size = (screen_size - border * n) / n 


run = True
while run:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            run = False
        
    screen.fill(WHITE)

    for i in range(n):
        for j in range(n):
            x = j * (cell_size + border) 
            y = i * (cell_size + border)

            color = RED if grid[i][j] == 1 else GREY
            pg.draw.rect(screen, color, (x, y, cell_size, cell_size))
    

    apply_rule(grid)

    clock.tick(20)
    pg.display.flip()


pg.quit()

