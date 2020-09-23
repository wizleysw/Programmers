def solution(a):
    
    if len(a) <= 2:
        return len(a)
    
    answer = 2

    min_l = a[0]
    min_r = a[-1]
    
    res = set()
    
    for i in range(1, len(a)-1):
        # 앞 부분보다 현재 인덱스 값이 작은 경우에 선택이 가능
        if min_l > a[i]:
            res.add(a[i])
            min_l = a[i]
        # 뒷 부분보다 현재 인덱스의 값이 작은 경우에도 선택이 가능
        if min_r > a[-1-i]:
            res.add(a[-1-i])
            min_r = a[-1-i]
            
    answer += len(res)
    return answer
