def bisect(n, times, l, r):
    if l>=r:
        return l
    
    mid = (int)((l+r)/2)
    
    cnt = 0
    for time in times:
        cnt += (int)(mid/time)
        
    if cnt < n:
        return bisect(n, times, mid+1, r)
    else:
        return bisect(n, times, l, mid)

def solution(n, times): 
    answer = bisect(n,times,1,1000000000*n)
    return answer
