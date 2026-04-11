import pygame as pg


pg.init()
screen_size = 600
screen = pg.display.set_mode((screen_size, screen_size))


WHITE  = (255, 255, 255)
BLUE  = (0, 0, 255)
BLACK  = (0, 0, 0)


run = True
while run:
    for event in pg.event.get():
        if event.type == pg.KEYDOWN:
            if event.key == pg.K_q:
                run = False
            

    screen.fill(BLACK)

    start_cor = (140.0, 50.0)
    n = 5
    shift = ()
    for j in range(n):
        for i in range(1, n+1):
            x = (start_cor[0] * j)
            y = start_cor[1] * i
            pg.draw.circle(screen, BLUE, (x, y), 10.0, 5 , True, True, True, True)

    



    pg.display.flip()

pg.quit()