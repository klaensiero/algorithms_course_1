import sys


def root(i):
    return (i-1)//2


def sift_down(m, i, n):
    while (2*i+1 < n):
        l = 2*i+1
        r = 2*i+2
        o = l
        if (r < n and m[r][0] < m[l][0]):
            o = r
        if (m[i][0] <= m[o][0]):
            break
        m[o], m[i] = m[i], m[o]
        i = o


def sift_up(mas1, i):
    while (mas1[i][0] < mas1[root(i)][0] and i >= 1):
        mas1[i], mas1[root(i)] = mas1[root(i)], mas1[i]
        i = root(i)


def extract_min(mas, n):
    h = mas[0][0]
    mas[0] = mas[n-1]
    mas.pop(n-1)
    sift_down(mas, 0, n-1)
    return h


def decrease_key(arr, x1, y1, tail):
    x = x1
    y = y1
    for i in range(tail):
        if arr[i][1] == x:
            arr[i][0] == y
            sift_up(arr, i)
            break


arr = []
l = 0
k = 0
itog = sys.stdin.read().splitlines()
for i in itog:
    s = i.split()
    if s[0] == "push":
        k += 1
        l += 1
        arr.append([int(s[1]), k])
        sift_up(arr, l-1)
    elif s[0] == "extract-min":
        k += 1
        if l == 0:
            print("*")
        else:
            print(extract_min(arr, l))
            l -= 1
    elif s[0] == "decrease-key":
        k += 1
        x = int(s[1])
        y = int(s[2])
        for i in range(l):
            if arr[i][1] == x:
                arr[i][0] = y
                sift_up(arr, i)
                break
