def count_func(T, X):
    k = 0
    indices = []
    for i in range(len(T)):
        if T[i:i + len(X)] == X:
            k += 1
            indices.append(i)

    return k, indices


T = input()
X = input()
res = list(count_func(T, X))

print(res[0])
print(' '.join(map(str, res[1])))
