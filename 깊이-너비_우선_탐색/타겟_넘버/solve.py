result = 0

def dfs(numbers, target, pos, cur):
    global result
    if pos == len(numbers):
        if cur == target:
            result += 1
        return
    
    dfs(numbers, target, pos+1, cur+numbers[pos])
    dfs(numbers, target, pos+1, cur-numbers[pos])

def solution(numbers, target):
    global result
    
    dfs(numbers, target, 0, 0)
    
    return result
