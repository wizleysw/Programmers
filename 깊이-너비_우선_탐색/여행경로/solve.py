import copy

max_v = []
visited = []
edge = []
airport = []
tsize = 0
res = []

def dfs(st, pos, end, result):
    global maxv, visited, edge, tsize, res
    
    if pos == end and len(result) == tsize+1:
        if len(res) != len(result):
            res = copy.deepcopy(result)
        return
    
    for i in range(len(edge[st])):
        next = edge[st][i]
        
        if not visited[st][next] or maxv[st][next]>visited[st][next]:
            result.append(next)
            visited[st][next] += 1
            dfs(next, pos+1, end, result)
            visited[st][next] -= 1
            del result[-1]
    
def solution(tickets):
    global maxv, visited, edge, airport, tsize, res
    
    tsize = len(tickets)

    for ticket in tickets:
        airport.append(ticket[0])
        airport.append(ticket[1])
        
    airport = list(set(airport))
    airport.sort()
    
    visited = [0 for i in range(len(airport))]
    edge = [[] for i in range(len(airport))]
    maxv = [[0 for j in range(len(airport))] for i in range(len(airport))]
    visited = [[0 for j in range(len(airport))] for i in range(len(airport))]

    for ticket in tickets:
        f = airport.index(ticket[0])
        t = airport.index(ticket[1])
        maxv[f][t] += 1
        edge[f].append(t)
    
    for x in edge:
        x.sort()
    
    st = airport.index("ICN", 0)
    dfs(st, 0, len(tickets), [st])
    
    answer = []
    for i in res:
        answer.append(airport[i])
    
    return answer
