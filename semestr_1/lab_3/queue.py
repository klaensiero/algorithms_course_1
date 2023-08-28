class linkedlist:
    def __init__(self):
        self.head = None
        self.end = None
        self.length = 0

    def push(self, new_el):
        node = Node(new_el)
        if (not self.end):
            self.head = node
        else:
            self.end.next = node
        self.end = node
        self.length += 1

    def pop(self):
        if (self.head != self.end):
            res = self.head
            self.head = self.head.next
            self.length -= 1
            return res
        res = self.head
        self.head = None
        self.end = None
        self.length -= 1
        return res


class Node:
    def __init__(self, elem):
        self.elem = elem
        self.next = None

    def __str__(self):
        return str(self.elem)


s = linkedlist()
rmved = []
n = int(input())
for i in range(n):
    i = (input())
    if ('+' in i):
        i = int(i[2:])
        s.push(i)
    else:
        rmved.append(s.pop())
for i in rmved:
    print(i)
