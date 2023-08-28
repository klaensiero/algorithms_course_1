import sys


class Tree:
    def __init__(self):
        self.parent = Node()

    def indexate(self, letter):
        return ord(letter)-97

    def init_Node(self):
        return Node()

    def insert(self, word):
        Trie_tree = self.parent
        for l in range(len(word)):
            if (word[l] not in Trie_tree.children):
                Trie_tree.children[word[l]] = Node()
            Trie_tree = Trie_tree.children[word[l]]
        Trie_tree.ending = True

    def find(self, word):
        Trie_tree = self.parent
        for l in range(len(word)):
            if (word[l] not in Trie_tree.children):
                return False
            Trie_tree = Trie_tree.children[word[l]]
        return Trie_tree.ending


class Node:
    def __init__(self):
        self.ending = False
        self.children = {}


input = open(0).readline
tree1 = Tree()
tree2 = Tree()
tree3 = Tree()
n = int(input())
p1 = ()
p2 = ()
p3 = ()
p1 = input().split()
p2 = input().split()
p3 = input().split()
m1, m2, m3 = 3*n, 3*n, 3*n
for i in range(n):
    tree1.insert(p1[i])
    tree2.insert(p2[i])
    tree3.insert(p3[i])
for i in range(len(p1)):
    if (tree3.find(p1[i]) and tree2.find(p1[i])):
        m1 -= 3
        m2 -= 3
        m3 -= 3
    elif (tree3.find(p1[i])):
        m1 -= 2
        m3 -= 2
    elif (tree2.find(p1[i])):
        m1 -= 2
        m2 -= 2
for i in range(len(p2)):
    if (tree3.find(p2[i]) and not tree1.find(p2[i])):
        m3 -= 2
        m2 -= 2
print(m1, m2, m3)
