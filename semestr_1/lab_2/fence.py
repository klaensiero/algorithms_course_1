def merges(inp_arr):
    if len(inp_arr) == 1:
        return inp_arr
    middle = len(inp_arr)//2
    l_part = merges(inp_arr[:middle])
    r_part = merges(inp_arr[middle:])
    return partition(l_part, r_part)


def partition(left_part, right_part):
    res = []
    x = len(left_part)
    y = len(right_part)
    i = 0
    j = 0
    while (x > i and j < y):
        if (left_part[i][0] <= right_part[j][0]):
            res.append(left_part[i])
            i += 1
        else:
            res.append(right_part[j])
            j += 1
    res += left_part[i:]+right_part[j:]
    return res


n = int(input())
arr = []
for i in range(n):
    inp_arr = list(map(int, input().split()))
    arr.append([inp_arr[0], inp_arr[1]])
arr = merges(arr)
count_fence = 0
first = arr[0][0]
last = arr[0][1]
for i in range(1, n):
    if (last < arr[i][1]):
        if (arr[i][0] <= last):
            last = arr[i][1]
        else:
            count_fence += last-first+1
            first, last = arr[i]
count_fence += last-first+1
print(count_fence)
