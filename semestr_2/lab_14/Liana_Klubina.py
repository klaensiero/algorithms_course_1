import sys


def func_count_repeated(n, txt_song, questions):
    count = 0
    for q in questions:
        i, j, k = q
        w1 = txt_song[i-1:i-1+k]
        w2 = txt_song[j-1:j-1+k]
        if (w1 == w2):
            count += 1

    return count


input = open(0).readline
n, m = map(int, input().split())
txt_song = input().strip()
questions = []
for i in range(m):
    i, j, k = map(int, input().split())
    questions.append((i, j, k))

print(func_count_repeated(n, txt_song, questions))
