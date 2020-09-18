def solution(people, limit):
    people.sort()
    
    left = 0
    right = len(people)-1
    
    cnt = 0
    while left <= right:
        if left == right:
            pass
        if people[left] + people[right] > limit:
            right-=1
        else:
            left+=1
            right-=1
        cnt += 1
        
    return cnt
