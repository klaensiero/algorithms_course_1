l = int(input())
mass = list(map(int, input().split()))
for i in range(1, l):
    key = mass[i]
    j = i-1
    while (j >= 0) and (key < mass[j]):
        mass[j+1] = mass[j]
        j -= 1
    mass[j+1] = key
print(*mass)
