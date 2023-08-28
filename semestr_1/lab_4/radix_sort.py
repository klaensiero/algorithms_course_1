def radsort(arr, m, p):
    k = 0
    for i in range(m-1, -1, -1):
        c_sort(arr, i)
        if (k+1 == p):
            for i in range(len(arr)):
                print(arr[i])
        k += 1


def c_sort(arr, t):
    o = [0]*26
    c = [0]*len(arr)
    for i in range(0, len(arr)):
        o[ord(arr[i][t])-97] += 1
    for i in range(1, 26):
        o[i] += o[i-1]
    for i in range(len(arr)-1, -1, -1):
        c[o[ord(arr[i][t])-97]-1] = arr[i]
        o[ord(arr[i][t])-97] -= 1
    for i in range(0, len(arr)):
        arr[i] = c[i]


arr = []
s = ''
inp_arr = list(map(int, input().split()))
n = inp_arr[0]
m = inp_arr[1]
k = inp_arr[2]
for i in range(n):
    s = input()
    arr.append(s)
radsort(arr, m, k)
