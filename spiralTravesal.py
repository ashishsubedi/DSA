grid = [[1,  2,  3,  4,  5],
        [6,  7,  8,  9,  10],
        [11, 12, 13, 14, 15],
        [16, 17, 18, 19, 20],
        [21, 22, 23, 24, 25]]


def matrix_spiral_print(M):
    rows = len(grid)
    cols = len(grid[0])
    total = rows*cols
    x = 0
    y = 0

    count = 0
    while(True):
        for r in range(x, cols-x):
            print(grid[x][r], end=" ")
            count += 1
        if(count >= total):
            break
        for c in range(y, rows-y-1):
            print(grid[c+1][cols-y-1], end=" ")
            count += 1
        if(count >= total):
            break
        for r in range(cols-x-2, x-1, -1):
            print(grid[rows-x-1][r], end=" ")
            count += 1
        y += 1
        if(count >= total):
            break
        for c in range(rows-y-1, y-1, -1):
            print(grid[c][x], end=" ")
            count += 1
        x += 1
        if(count >= total):
            break


matrix_spiral_print(grid)
