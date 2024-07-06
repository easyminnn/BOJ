N, M = map(int, input().split())

# 웅덩이 정보를 저장할 리스트
arr = []

for _ in range(N):
    arr.append(list(input()))

check = min(N, M)

answer = 1

for i in range(N):
    for j in range(M):
        for k in range(check):
            if i + k < N and j + k < M:
                if arr[i][j] == arr[i + k][j] and arr[i][j] == arr[i][j + k] and arr[i][j] == arr[i + k][j + k]:
                    answer = max(answer, (k + 1)**2)

print(answer)