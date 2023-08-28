l = int(input())
mass = list(map(int, input().split()))
temp = mass[-1]
for i in range(l-1, 0, -1):
    mass[i] = mass[i-1]
mass[0] = temp
print(*mass)
