from queue import Queue

def solution(begin, target, words):
    flag = False
    
    # 아예 못만드는 경우
    for w in words:
        if w == target:
            flag = True
            break
            
    if not flag:
        return 0
    
    visited = [0 for i in range(len(words))]
    queue = Queue()
    queue.put(begin, 0)
    
    count = 0
    while not queue.empty():
        queue2 = Queue()
        while not queue.empty():
            cur = queue.get()
            
            if cur == target:
                break
                
            for i in range(len(words)):
                word = words[i]
                cnt = 0
                for j in range(len(cur)):
                    if cur[j] != word[j]:
                        cnt += 1
                if cnt == 1 and not visited[i]:
                    queue2.put(word)
                    visited[i] = True

        queue = queue2
        count += 1
        
    return count-1
