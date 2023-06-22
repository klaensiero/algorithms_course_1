def dfs_func(i, j):
    if (i < 0 or i >= n or j < 0 or j >= m or house[i][j] != 1):
        return
    house[i][j] = 2
    dfs_func(i+1, j)
    dfs_func(i-1, j)
    dfs_func(i, j+1)
    dfs_func(i, j-1)

n, m = map(int, input().split())
rooms = 0
house = [[0]*m for i in range(n)]
for i in range(n):
    line = input()
    for j in range(m):
        if line[j] == '.':
            house[i][j] = 1

for i in range(n):
    for j in range(m):
        if house[i][j] == 1:
            dfs_func(i, j)
            rooms += 1

print(rooms)