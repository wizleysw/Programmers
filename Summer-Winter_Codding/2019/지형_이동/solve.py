from queue import Queue, PriorityQueue

answer = 0
union_set = []
connected = []
visited = []
edge = []
row = 0
col = 0

dx = [-1,1,0,0]
dy = [0,0,-1,1]

pq = PriorityQueue()

def bfs(land, height, x, y, div):
    global visited, row, col, dx, dy

    visited[x][y] = div

    que = Queue()
    que.put([x,y])
    
    while not que.empty():
        cur = que.get()
        cx = cur[0]
        cy = cur[1]
        
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            
            if nx<0 or ny<0 or nx>=row or ny>=col:
                continue
                
            if not visited[nx][ny] and abs(land[nx][ny]-land[cx][cy])<=height:
                visited[nx][ny] = div
                que.put([nx,ny])
                
def connectEdge(land):
    global visited, row, col, dx, dy, edge
    
    for i in range(row):
        for j in range(col):
            cur_div = visited[i][j]
            
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                
                if nx<0 or ny<0 or nx>=row or ny>=col:
                    continue
                    
                k_div = visited[nx][ny]                    
                
                if cur_div != k_div:
                    edge.append([abs(land[i][j]-land[nx][ny]), cur_div, k_div])
        
def findSet(x):
    global union_set
    
    if union_set[x] == x:
        return x
    
    union_set[x] = findSet(union_set[x])
    return union_set[x]

def unionSet(a, b):
    global union_set
    
    if a>b:
        a, b = b, a
    
    a = findSet(a)
    b = findSet(b)
    union_set[b] = a
    
def kruskal(limit):
    global edge, answer
    
    edge.sort()

    cnt = 0
    for e in edge:
        
        if cnt == limit:
            return
        
        w = e[0]
        a = e[1]
        b = e[2]
        
        if findSet(a) != findSet(b):
            unionSet(a,b)
            answer += w
            cnt += 1
        
def prim(start):
    global row, col, edge, pq, answer, connected
    
    connected[start] = True

    for next in range(len(edge)):
        if connected[next] or edge[start][next] == 10000:
            continue
        pq.put([edge[start][next], next])
    
    while not pq.empty():
        c = pq.get()
        w = c[0]
        next = c[1]
        
        if connected[next]:
            continue
        
        answer += w
        prim(next)

def solution(land, height):
    global visited, row, col, edge, answer, connected, union_set

    row = len(land)
    col = len(land[0])
    visited = [[0 for i in range(col)] for i in range(row)]
    
    div = 1
    for i in range(row):
        for j in range(col):
            if not visited[i][j]:
                bfs(land, height, i, j, div)
                div += 1
                
    connectEdge(land)
    union_set = [i for i in range(div)]
    kruskal(div-2)
    
    return answer
