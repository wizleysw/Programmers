from queue import Queue

visited = []
edge = []

def bfs(start):
    global visited, edge
    
    que = Queue()
    visited[start] = True
    que.put(start)
    
    while not que.empty():
        cur = que.get()
        
        for next in edge[cur]:
            if not visited[next]:
                que.put(next)
                visited[next] = True

def solution(n, computers):
    global visited, edge
    
    visited = [False for i in range(n)]
    edge = [[] for i in range(n)]    
    answer = 0
    
    for i in range(len(computers)):
        for j in range(n):
            if(computers[i][j]) and i != j:
                edge[i].append(j)
                 
    cnt = 0
    for i in range(n):
        if not visited[i]:
            bfs(i)
            cnt+=1
            
    return cnt
