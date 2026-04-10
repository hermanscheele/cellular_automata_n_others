




def init_tensor(n):
    grid = []
    for i in range(n):
        grid.append([])
        for j in range(n):
            grid[i].append([])
            for k in range(n):
                grid[i][j].append(0)

    return grid 


def get_matricies(tensor):
    m = []
    n = len(tensor)
    for k in range(n):
        matrix = [[tensor[i][j][k] for j in range(n)] for i in range(n)]
        m.append(matrix)
    return m


def render_tensor(tensor):
    m = get_matricies(tensor)
    for matrix in m:
        for row in matrix:
            print(row)
        print("")


def apply_rule_tensor(tensor):

    # 4 corners
    # 6 walls
    # interior
    # etc. ..

    pass

tensor = init_tensor(3)
tensor[2][1][2] = 99


render_tensor(tensor)
n = len(tensor)

