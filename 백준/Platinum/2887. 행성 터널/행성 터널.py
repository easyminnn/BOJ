import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

# 유니온 파인드
def find(u):
    if parent[u] != u:
        parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    u = find(u)
    v = find(v)
    if u != v:
        parent[v] = u
        return True
    return False

# 입력
n = int(input())
planets = []
for i in range(n):
    x, y, z = map(int, input().split())
    planets.append((i, x, y, z))

edges = []

# x, y, z 각각 정렬한 후 인접한 행성들 간선 추가
for dim in range(1, 4):
    planets.sort(key=lambda x: x[dim])
    for i in range(n - 1):
        a, b = planets[i], planets[i + 1]
        cost = abs(a[dim] - b[dim])
        edges.append((cost, a[0], b[0]))

# 크루스칼 알고리즘
edges.sort()
parent = list(range(n))
total_cost = 0
count = 0

for cost, u, v in edges:
    if union(u, v):
        total_cost += cost
        count += 1
        if count == n - 1:
            break

print(total_cost)
