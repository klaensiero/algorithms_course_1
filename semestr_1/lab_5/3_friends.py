n = int(input())
p1 = input().split()
p2 = input().split()
p3 = input().split()
m1, m2, m3 = 3*n, 3*n, 3*n

for i in p1:
    if i in p2 and i in p3:
        m1 -= 3
    if i in p2 and i not in p3:
        m1 -= 2
        m2 -= 2
for i in p2:
    if i in p1 and i in p3:
        m2 -= 3
    if i in p3 and i not in p1:
        m2 -= 2
        m3 -= 2
for i in p3:
    if i in p2 and i in p1:
        m3 -= 3
    if i in p1 and i not in p2:
        m1 -= 2
        m3 -= 2
print(m1, m2, m3)
