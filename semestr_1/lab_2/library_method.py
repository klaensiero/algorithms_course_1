l = int(input())
mass = list(map(int, input().split()))
for i in range(1, l):
    f = False
    key = mass[i]
    j = i - 1
    while (j >= 0) and (key < mass[j]):
        mass[j+1] = mass[j]
        j -= 1
        f = True
    mass[j+1] = key
    if f == True:
        print(*mass)
