#include <math.h>
#include <iostream>

int solution(vector<int> &A) 
{
    int right_sum = 0;
    int left_sum = 0;
    int minimal_difference = 0;
    
    for (vector<int>::iterator it = A.begin() ;  it != A.end() ; it++)
    {
        if (it == A.begin())
        {
            left_sum += *it;
        }
        else
        {
            right_sum += *it;
        }
    }

    minimal_difference = abs(left_sum - right_sum);

    for (unsigned int i = 1 ;  i < A.size()-1 ; i++)
    {
        left_sum += A[i];
        right_sum -= A[i];

        int difference = abs(left_sum - right_sum);

        if (difference < minimal_difference)
        {
            minimal_difference = difference;
        }

    }

    return minimal_difference;
}
