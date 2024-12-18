import sys
N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    if A[i] % 2 == 0:
        A[i] = 2
    else:
        A[i] = 1

count1 = 0
count2 = 0 
count3 = 0
count4 = 0
meet1 = 0
meet2 = 0

for i in range(N):
    if A[i] == 1:
        meet1 +=1 
        count1 += i - 0 + meet1 - 1
        count2 += N - i  - 1 - meet1 + 1
    if A[i] == 2:
        meet2 += 1
        count3 += i - 0 + meet2 - 1
        count4 += N - i  - 1 - meet2 + 1

print(min(count1 , count4, count2 , count3))