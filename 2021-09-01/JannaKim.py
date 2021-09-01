v = "AEIOU"


def combine(* args):
    res = ''
    for idx in args:
        res += v[idx] 
    return res
        
def solution(word):
    cnt = 0
        
    for i in range(5):
        cnt += 1
        res = combine(i)
        
        if res == word:
            return cnt
        
        for j in range(5):
            cnt += 1
            res = combine(i, j)
            
            if res == word:
                return cnt
                
            for k in range(5):
                cnt += 1
                res = combine(i, j, k)
                
                if res == word:
                    return cnt
                    
                for l in range(5):
                    cnt += 1
                    res = combine(i, j, k, l)
                    
                    if res == word:
                        return cnt
                        
                    for m in range(5):
                        cnt += 1
                        res = combine(i, j, k, l, m)
                        
                        if res == word:
                            return cnt
                        
    return -1