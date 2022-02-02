#include <bits/stdc++.h>

int solution(vector<int> &A) 
{
	int max_intersec = 10000000;
	
    std::vector<long long> open_vector;
    std::vector<long long> close_vector;

    for (unsigned int i = 0 ; i < A.size() ; i++)
    {
        long long open = (long long)(i) - A[i];
        long long close = (long long)(i) + A[i];

        open_vector.push_back(open);
        close_vector.push_back(close);
    }

    sort(open_vector.begin(), open_vector.end());
    sort(close_vector.begin(), close_vector.end());

    unsigned int cumulative_opened = 0;
    unsigned int cumulative_closed = 0;

    int intersecs = 0;

    while (cumulative_opened < open_vector.size())
    {
        if (open_vector[cumulative_opened] <= close_vector[cumulative_closed])
        {
            intersecs += cumulative_opened - cumulative_closed;
            cumulative_opened++;
        }
        else if (open_vector[cumulative_opened] > close_vector[cumulative_closed])
        {
            cumulative_closed++;
        }
        
        if (intersecs > max_intersec)
		{
			return -1;
		}
        
    }
    return intersecs;
}