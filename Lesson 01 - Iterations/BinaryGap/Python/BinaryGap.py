def solution(N):
    
    started = False
    count_gap = 0
    biggest_gap = 0
    while N > 0:

        if (N & 0x01) == 0x01 :
            if started :
                if count_gap > biggest_gap :
                    biggest_gap = count_gap
            count_gap = 0
            started = True

        else :
            count_gap += 1
        
        N = N  >> 1;


    return biggest_gap