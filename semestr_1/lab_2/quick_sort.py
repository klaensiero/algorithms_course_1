def quicks(arr):
    if len(arr) <= 1:
        return arr
    op_elem = arr[0]
    left_part = [i for i in arr if i < op_elem]
    middle = [i for i in arr if i == op_elem]
    right_part = [i for i in arr if i > op_elem]
    return quicks(left_part) + middle + quicks(right_part)


l = int(input())
arr = list(map(int, input().split()))
input_arr = quicks(arr)
print(*input_arr)
