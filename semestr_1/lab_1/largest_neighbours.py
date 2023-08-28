lenm = int(input())
mass = list(map(int, input().split()))
k = 0
for i in range(1, lenm-1):
    if mass[i] > mass[i-1] and mass[i] > mass[i+1]:
        k += 1
print(k)
