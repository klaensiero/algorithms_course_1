class DSU:
    def __init__(self, n):
        self.r = [0] * n
        self.p = list(range(n))

    def add(self, v, u):
        v = self.get(v)
        u = self.get(u)
        if v == u:
            return
        if self.r[v] < self.r[u]:
            v, u = u, v
        self.p[u] = v
        if self.r[v] == self.r[u]:
            self.r[v] += 1

    def get(self, v):
        if self.p[v] == v:
            return v
        self.p[v] = self.get(self.p[v])
        return self.p[v]

    def check_scc(self, v, u):
        v = self.get(v)
        u = self.get(u)
        return v == u


def read_G():
    n, m, q = map(int, input().split())
    queries = list()
    union_d = DSU(n)

    G = {}
    for i in range(m):
        v, u = map(int, input().split())
        G[(min(v, u) - 1, max(v, u) - 1)] = True

    for i in range(q):
        c, v, u = input().split()
        v, u = int(v), int(u)
        if c == '?':
            queries.append((0, v - 1, u - 1))
        else:
            queries.append((1, v - 1, u - 1))
            G.pop((min(v, u) - 1, max(v, u) - 1), None)

    for p in G:
        union_d.add(p[0], p[1])
    return union_d, queries


def printResult(result):
    for i in result:
        if i > 0:
            print("YES")
        if i < 0:
            print("NO")


union_d, queries = read_G()
size = len(queries)
result = [0] * size

for i in range(size-1, -1, -1):
    if queries[i][0]:
        union_d.add(queries[i][1], queries[i][2])
    else:
        if union_d.check_scc(queries[i][1], queries[i][2]):
            result[i] = 1
        else:
            result[i] = -1

printResult(result)
