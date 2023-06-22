def cast_spell(w):
    lengths = suffix_func(w)
    res = ' '.join(str(i) for i in lengths)
    return res

def suffix_func(w):
    suffixes = [0] * len(w)
    lengths = [0] * len(w)
    for i in range(1, len(w)):
        j = suffixes[i - 1]
        while j > 0 and w[i] != w[j]:
            j = suffixes[j - 1]
        if w[i] == w[j]:
            j += 1
        suffixes[i] = j

    for i in range(len(w)):
        lengths[i] = suffixes[i]

    return lengths

print(cast_spell(input()))
