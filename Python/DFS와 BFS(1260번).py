from collections import deque 
'''
deque는 리스트의 양쪽 끝에서 데이터의 삽입, 삭제가 가능한 선형리스트
'''
def bfs(start):
    dq = deque()
    dq.append(start)
    visit.append(start)

    #dq가 비어있지 않으면 동작
    while dq:
        start = dq.popleft() #dq의 제일 왼쪽 원소를 제거 
        print(start, end=' ')
        for i in graph[start]:
            if i not in visit:
                dq.append(i)
                visit.append(i)

def dfs(start):
    visit.append(start)
    print(start,end=' ')
    for i in graph[start]:
        if i not in visit:
            dfs(i)

N,M, node = map(int, input().split())
graph = [[] for i in range(N+1)]
visit = []

for i in range(M):
    U, V = map(int, input().split())
    graph[U].append(V)
    graph[V].append(U)
    
for i in graph:
    i.sort()

dfs(node)
visit=[]
print()
bfs(node)