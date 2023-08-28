class Stack:
    def __init__(self):
        self.arr = []
        self.max = []

    def empty(self):
        return self.arr == []

    def push(self, elem):
        if (len(self.arr) == 0):
            self.max.append(int(elem))
        elif (self.max[len(self.arr)-1] < int(elem)):
            self.max.append(int(elem))
        else:
            self.max.append(self.max[len(self.arr)-1])
        self.arr.append(elem)


def max_pop(self):
    if (self.empty()):
        return 'None'
    return self.max[len(self.arr)-1]


def pop(self):
    if (self.empty()):
        return 'no'
    self.max.pop()
    return self.arr.pop()


s = Stack()
rmved = []
n = int(input())
for i in range(n):
    elems = input().split()
    if (elems[0] == '+'):
        s.push(elems[1])
    if (elems[0] == '-') and (pop(s) == 'no'):
        rmved.append('no')
    if (elems[0] == 'max'):
        rmved.append(max_pop(s))
for i in range(len(rmved)):
    print(rmved[i])
