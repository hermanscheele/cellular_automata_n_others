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

    pg.draw.circle(screen, BLUE, (10.0,10.0), 30.0, 3, True, True, True, True)

    



    pg.display.flip()

pg.quit()