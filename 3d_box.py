import pygame as pg
from OpenGL.GL import *
from OpenGL.GLU import *


vertices = [
    (1, 1, -1), (-1, 1, -1), (-1,-1,-1), (1,-1,-1),  # back
    (1, 1,  1), (-1, 1,  1), (-1,-1, 1), (1,-1, 1),  # front
]

faces = [
    (0,1,2,3),  # back
    (4,5,6,7),  # front
    (0,4,7,3),  # right
    (1,5,6,2),  # left
    (0,1,5,4),  # top
    (3,2,6,7),  # bottom
]

edges = [
    (0,1),(1,2),(2,3),(3,0),  # back
    (4,5),(5,6),(6,7),(7,4),  # front
    (0,4),(1,5),(2,6),(3,7),  # sides
]



def draw_cube():
    glBegin(GL_QUADS)
    for face in faces:
        for vertex_index in face:
            glVertex3fv(vertices[vertex_index])
    glEnd()

def draw_edges():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex_index in edge:
            glVertex3fv(vertices[vertex_index])
    glEnd()


pg.init()
screen = pg.display.set_mode((500, 500), pg.DOUBLEBUF | pg.OPENGL)

gluPerspective(45, 500/500, 0.1, 50)
glTranslatef(0, 0, -10)


run = True
while run:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            run = False
    

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glColor3f(1, 1, 1)
    draw_cube()

    glColor3f(0, 0, 0)
    draw_edges()
    
    glRotatef(0.01, 1, 1, 1)

    pg.display.flip()



pg.quit()