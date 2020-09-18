def solution(routes):
    routes.sort()
    
    end = routes[0][1]
    
    cnt = 1
    for i in range(1, len(routes)):
        # 시작 지점이 end지점보다 작은 경우
        if routes[i][0] <= end:
            end = min(end, routes[i][1])
        # 그 외는 도착 지점을 end로 최신화 
        else:
            cnt += 1
            end = routes[i][1]
            
    return cnt
