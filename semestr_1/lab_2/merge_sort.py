def merges(arr):
    if len(arr) >= 2:
        i = 0
        j = 0
        m = 0
        middle = len(arr) // 2
        left_p = [arr[x] for x in range(0, middle)]
        right_p = [arr[x] for x in range(middle, len(arr))]
        merges(left_p)
        merges(right_p)

        while (j < len(right_p) and i < len(left_p)):
            if left_p[i] <= right_p[j]:
                arr[m] = left_p[i]
                i += 1
            else:
                arr[m] = right_p[j]
                j += 1
            m += 1
        while (i < len(left_p)):
            arr[m] = left_p[i]
            i += 1
            m += 1
        while (j < len(right_p)):
            arr[m] = right_p[j]
            j += 1
            m += 1


l = int(input())
inp_arr = list(map(int, input().split()))
merges(inp_arr)
print(*inp_arr)
