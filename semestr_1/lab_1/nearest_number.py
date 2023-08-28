lenm = int(input())
mass = list(map(int, input().split()))
x = int(input())
smol_diff = 2000
smol_count = 0
for i in range(0, lenm):
    diff = abs(x-mass[i])
    if diff <= smol_diff:
        smol_diff = diff
        smol_count = i
print(mass[smol_count])
