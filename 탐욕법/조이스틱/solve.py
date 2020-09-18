def solution(name):
    
    diff = []
    
    for i in range(len(name)):
        f = ord(name[i])-ord('A')
        e = ord('Z')-ord(name[i])+1
        
        diff.append(min(f,e))
        
    total = 0
    for n in diff:
        total += n
        
    max_hole = 0
    hole_l = 0
    hole_r = 0
    for i in range(len(diff)):
        if diff[i]==0:
            hole = i
            for j in range(i, len(diff), 1):
                if diff[j] == 0:
                    hole = j
                else :
                    break
            if hole-i+1 > max_hole:
                max_hole = hole-i+1
                hole_l = i
                hole_r = hole

    hole_escape = total
    if hole_l-0 >= 1:
        hole_escape += (hole_l-1)*2
        
    if hole_r != len(diff)-1:
        hole_escape += 1
    
        if len(diff)-1 - hole_r >= 1:
            hole_escape += len(diff)-1-hole_r-1

    left_to_right = total
    for i in range(1, len(diff), 1):
        left_to_right += 1
            
    return min(left_to_right,hole_escape)
