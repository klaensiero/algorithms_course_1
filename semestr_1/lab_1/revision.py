lenm = int(input())
arr = list(map(int, input().split()))
min1 = max(arr)
min2 = max(arr)

for i in range(lenm):
    min1 = min(arr[i], min1)

for i in range(lenm):
    if arr[i] == min1:
        arr.remove(arr[i])
        break

for i in range(lenm-1):
    min2 = min(min2, arr[i])

print(min1, min2)
