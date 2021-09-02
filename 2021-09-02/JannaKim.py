def solution(table, languages, preference):
    occupation = {}
    
    for line in table:
        line = line.split()
        occupation[ line[0] ] = line[1:]
        
    ans = ""
    mx = -1
    
    for k, v in occupation.items():
        score = 0
        for lang, pref in zip(languages, preference):
            for i in range(5):
                if v[i] == lang:
                    score += (5 - i) * pref
                    break
                    
        if score > mx:
            mx = score
            ans = k
            
        elif score == mx:
            if ans > k:
                ans = k

    return ans