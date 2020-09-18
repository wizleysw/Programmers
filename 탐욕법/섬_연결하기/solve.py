from queue import PriorityQueue

edge = []
sets = []
pq = PriorityQueue()

def findParent(x):
    global sets
    if sets[x] == x:
        return x
    else :
        sets[x] = findParent(sets[x])
        return sets[x]

def unionTwo(x, y):
    global sets
    
    x = findParent(x)
    y = findParent(y)
    sets[y] = x
    
    
def solution(n, costs):
    global edge, sets, pq
    
    answer = 0
    
    sets = [i for i in range(n)]

    for cost in costs:
        pq.put([cost[2], cost[0], cost[1]])
        
    while not pq.empty():
        cur = pq.get()
        w = cur[0]
        left = cur[1]
        right = cur[2]
        
        if findParent(left) != findParent(right):
            unionTwo(left, right)
            answer += w
        
    return answer
