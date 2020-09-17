def bisect(rocks, n, l, r):
    if l+1 >= r:
        return l
    
    mid = (int)((l+r)/2)
    
    before = 0
    cnt = 0
    for rock in rocks:
        if rock-before < mid:
            cnt += 1
        else :
            before = rock
    
    if cnt <= n:
        return bisect(rocks, n, mid, r)
    else :
        return bisect(rocks, n, l, mid)
        

def solution(distance, rocks, n):
    rocks.append(distance)
    rocks.sort()
    
    answer = bisect(rocks, n, 0, distance)
    return answer
