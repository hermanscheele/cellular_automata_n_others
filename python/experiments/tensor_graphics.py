import pygame as pg
from tensor_auto import init_tensor, get_matricies

pg.init()
clock = pg.time.Clock()
screen_size = 600
screen = pg.display.set_mode((screen_size, screen_size))

YELLOW = (255, 255, 0)
RED    = (225, 0, 0)
WHITE  = (255, 255, 255)
GREY   = (200, 200, 200)
BLACK  = (0, 0, 0)

n = 6
tensor = init_tensor(n)
tensor[0][0][3] = 1
matricies = get_matricies(tensor)


border = 1
box_border = 5
cell_size = (screen_size - (n - 1) * box_border) / (n * n) - border


run = True
while run:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            run = False
        
    screen.fill(BLACK)
    for k in range(n):

        grid = matricies[k]        
        for i in range(n):
            for j in range(n):
                x = j * (cell_size + border) + (k * ((cell_size + border) * n + box_border))
                y = i * (cell_size + border)


                color = RED if grid[i][j] == 1 else GREY
                pg.draw.rect(screen, color, (x, y, cell_size, cell_size))
            


    pg.display.flip()
    clock.tick(1)


pg.quit()

