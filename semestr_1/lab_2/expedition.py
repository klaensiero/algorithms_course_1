def insertion_sort(mass):
    for i in range(1, len(mass)):
        key = mass[i]
        j = i-1
        while (j >= 0) and (key < mass[j]):
            mass[j+1] = mass[j]
            j -= 1
        mass[j+1] = key
    return mass


boats = []
nm = list(map(int, input().split()))
n = nm[0]
m = nm[1]
for i in range(n):
    pt_1 = list(map(int, input().split()))
    for j in range(m):
        boats.append(pt_1[j])
mesk_count = int(input())
mesk_list = list(map(int, input().split()))
boats = insertion_sort(boats)
mesk_list = insertion_sort(mesk_list)
max_exp = 0
mesk_i = len(mesk_list)-1
boat_i = len(boats)-1
while (mesk_i+1 > 0) and (boat_i+1 > 0):
    if boats[boat_i] >= mesk_list[mesk_i]:
        mesk_i -= 1
        boat_i -= 1
        max_exp += 1
    else:
        mesk_i -= 1
print(max_exp)
