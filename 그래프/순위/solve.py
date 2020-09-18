dist = []

def floyd(n):
    global dist
    
    for i in range(n+1):
        for j in range(n+1):
            for k in range(n+1):
                if i==j or i==k or j==k:
                    continue
                if dist[j][i] and dist[i][k]:
                    dist[j][k] = True
                

def solution(n, results):
    global dist
    answer = 0
    
    dist = [[False for i in range(n+1)] for i in range(n+1)]
    
    for result in results:
        dist[result[0]][result[1]] = True
    
    floyd(n)
    
    for i in range(n+1):
        cnt = 0
        for j in range(n+1):
            if dist[i][j] or dist[j][i]:
                cnt += 1 
        if cnt == n-1:
            answer += 1

    return answer
