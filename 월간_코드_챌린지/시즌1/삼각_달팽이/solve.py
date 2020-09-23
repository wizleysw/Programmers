def solution(n):
    answer = []
    
    triangle = [[0]*x for x in range(1,n+1)]
    
    row = -1
    col = 0
    number = 1
    
    # n번 방향을 바꿈 왼쪽 대각선 -> 오른쪽 -> 오른쪽 대각선
    for i in range(n):
        for j in range(i,n):
            # 왼쪽 대각선
            if i%3 == 0:
                row += 1
            # 오른쪽 
            elif i%3 == 1:
                col += 1
            # 오른쪽 대각선
            else:
                row -= 1
                col -= 1
            triangle[row][col] = number
            number += 1
    
    answer = []
    
    for tri in triangle:
        for angle in tri:
            answer.append(angle)
            
    return answer
