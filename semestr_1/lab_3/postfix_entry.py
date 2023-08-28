class Stack:
    def __init__(self):
        self.elems = []

    def push(self, elem):
        self.elems.append(elem)

    def pop(self):
        return self.elems.pop()


opers = {"+": (lambda x, y: x+y), "-": (lambda x, y: x-y),
         "*": (lambda x, y: x*y), "/": (lambda x, y: x/y)}


def postfix(example):
    symbols = example.split()
    s = Stack()
    for sy in symbols:
        if (sy in opers):
            v1 = s.pop()
            v2 = s.pop()
            res = opers[sy](v2, v1)
            s.push(res)
        else:
            s.push(int(sy))
    return s.pop()


example = input()
res = postfix(example)
print(res)
