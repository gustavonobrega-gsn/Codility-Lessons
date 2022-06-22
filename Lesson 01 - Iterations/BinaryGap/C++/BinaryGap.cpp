int solution(int N) 
{    
    unsigned int max_gap = 0;
    unsigned int current_gap = 0;

    while ((N % 2 == 0))
    {
        N = N >> 1;
    }

    while (N > 0)
    {
        if (N % 2 == 1)
        {
            if (current_gap > max_gap)
            {
                max_gap = current_gap;
            }
            current_gap = 0;
        }

        else
        {
            current_gap++;
        }

        N = N >> 1;
    }

    return max_gap;
}
