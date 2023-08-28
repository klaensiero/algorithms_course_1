class linkedlist:
    def __init__(self):
        self.head = None

    def push(self, new_el):
        new_node = Node(new_el)
        new_node.next = self.head
        self.head = new_node

    def pop(self):
        if (self.head == None):
            return None
        temp = self.head
        self.head = self.head.next
        return temp


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
        s.push(Node(int(i[2:])))
    else:
        rmved.append(s.pop())
for i in range(len(rmved)):
    print(rmved[i])
