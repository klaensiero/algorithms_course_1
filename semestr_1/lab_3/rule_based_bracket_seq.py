import sys


def check(val):
    arr = []
    brackets = ["(", "{", "["]
    for i in val:
        if (i in brackets):
            arr.append(i)
        else:
            if (not arr):
                return "NO"
            cur_elem = arr.pop()
            if (cur_elem == "("):
                if (i != ")"):
                    return "NO"
            if (cur_elem == "{"):
                if (i != "}"):
                    return "NO"
            if (cur_elem == "["):
                if (i != "]"):
                    return "NO"
    if arr:
        return "NO"
    return "YES"


res = []
res = sys.stdin.read().splitlines()
for i in res:
    print(check(i))
