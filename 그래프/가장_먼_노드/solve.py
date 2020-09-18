from queue import Queue

visited = []
eg = []

def bfs(edge):
    global visited, eg
    start = 1
    
    que = Queue()
    que.put(start)
    visited[start] = True

    while not que.empty():
        que2 = Queue()
        cnt = que.qsize()

        while not que.empty():
            cur = que.get()

            for e in eg[cur]:
                if not visited[e]:
                    que2.put(e)
                    visited[e] = True
        
        que = que2
        
    return cnt

def solution(n, edge):
    global visited, eg
    
    visited = [False for i in range(n+1)]
    eg = [[] for i in range(n+1)]
    
    for i in range(len(edge)):
        f = edge[i][0]
        t = edge[i][1]
        eg[f].append(t)
        eg[t].append(f)
    
    return bfs(edge)
 
