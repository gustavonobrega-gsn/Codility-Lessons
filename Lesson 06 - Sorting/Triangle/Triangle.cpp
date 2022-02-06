#include <bits/stdc++.h>

//0 ≤ P < Q < R < N
//once sorted, 
//since A[Q] and A[R] are greater than A[P], A[P] < A[Q] + A[R]
//since A[R] is greater than A[Q],           A[Q] < A[P] + A[R]
//so, just need to check if A[R] < A[P] + A[Q]
//but since the elements can be at the limit from int, better check as A[R] - A[Q] < A[P] 

int solution(vector<int> &A) 
{
    if (A.size() >= 3)
    {
        sort(A.begin(), A.end());
    
        for (unsigned int R = 2 ; R < A.size() ; R++)
        {
            int P = R - 2;
            int Q = R - 1;

            if (A[P] >= 0)
            {
                if (A[P] > A[R] - A[Q])
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}
Analysis summ