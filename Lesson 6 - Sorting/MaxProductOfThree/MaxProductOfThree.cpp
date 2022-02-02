#include <bits/stdc++.h>

int solution(vector<int> &A) 
{
    unsigned int factors_size = 3;

    sort(A.begin(), A.end());

    int max_factor_lowest_values = 1;
    int max_factor_highest_values = 1;

    for (unsigned int i = 0, j = A.size() - 1 ; i < factors_size ; i++,j--)
    {
        max_factor_highest_values *= A[j];

        if (i == factors_size - 1)
        {
            max_factor_lowest_values *= A[A.size() - 1];
        }

        else 
        {
            max_factor_lowest_values *= A[i];
        }
    }

    return max_factor_lowest_values > max_factor_highest_values ? max_factor_lowest_values : max_factor_highest_values;
}
