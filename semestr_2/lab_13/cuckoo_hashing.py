class Hash_Table:
    def __init__(self):
        self.ending = False
        self.keys={}

class Cuckoo_hashing:
    def __init__(self):
        self.ht = Hash_Table()

    def hash_func(self,letter):
        return ord(letter) % 524

    def init_Node(self):
        return Hash_Table()

    def insert(self, word):
        Table = self.ht
        for l in range(len(word)):
            if (word[l] not in Table.keys):
                Table.keys[word[l]] = Hash_Table()
            Table = Table.keys[word[l]]
        Table.ending=True

    def find(self, word):
        Table = self.ht
        for l in range(len(word)):
            if (word[l] not in Table.keys):
                return False
            Table = Table.keys[word[l]]
        return Table.ending

    
input = open(0).readline
ht1 = Cuckoo_hashing()
ht2 = Cuckoo_hashing()
ht3 = Cuckoo_hashing()
n = int(input())
m1,m2,m3=3*n, 3*n, 3*n

p1=()
p2=()
p3=()
p1=input().split()
p2=input().split()
p3=input().split()


for i in range(n):
    ht1.insert(p1[i])
    ht2.insert(p2[i])
    ht3.insert(p3[i])
for i in range (len(p1)):
    if (ht3.find(p1[i]) and ht2.find(p1[i])):
        m1-=3
        m2-=3
        m3-=3
    elif (ht3.find(p1[i])):
        m1-=2
        m3-=2
    elif (ht2.find(p1[i])):
        m1-=2
        m2-=2
for i in range (len(p2)):
    if (ht3.find(p2[i]) and not ht1.find(p2[i])):
        m3-=2
        m2-=2

print(m1,m2,m3)