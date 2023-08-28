def right_part_search(arr, pivot, lp, rp):
    while (lp < rp):
        middle = (rp+lp)//2
        if arr[middle] == pivot:
            lp = middle+1
        if arr[middle] < pivot:
            lp = middle+1
        if arr[middle] > pivot:
            rp = middle-1
    if arr[rp] != pivot:
        if ((rp < 0) or (arr[rp-1] != pivot)):
            return -1
        else:
            return rp
    else:
        if (arr[rp-1] == pivot) and (arr[rp] > pivot):
            return rp
        else:
            return rp+1


def left_part_search(arr, pivot, lp, rp):
    while (rp > lp):
        middle = (rp+lp)//2
        if arr[middle] == pivot:
            rp = middle
        if arr[middle] < pivot:
            lp = middle+1
        else:
            rp = middle
    if (lp < 0 or arr[lp] != pivot):
        return -1
    else:
        return lp+1


n = int(input())
arr = list(map(int, input().split()))
arr = sorted(arr)
m = int(input())
query = list(map(int, input().split()))
for i in query:
    output_1 = left_part_search(arr, i, 0, n-1)
    output_2 = right_part_search(arr, i, 0, n-1)
    print(output_1, output_2)
