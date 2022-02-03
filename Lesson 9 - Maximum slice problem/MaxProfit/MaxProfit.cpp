int solution(vector<int> &A) 
{
    int max_profit = 0;

    if (A.size() >= 2)
    {
        int min_value = A[0];
        int max_value = A[1];
        
        max_profit = max_value - min_value;

        for (unsigned int i = 1 ; i < A.size()-1 ; i++)
        {
            if (A[i] < min_value)
            {
                min_value = A[i];
                max_value = A[i+1];
            }

            else if (A[i+1] > max_value)
            {
                max_value = A[i+1];
            }

            if (max_profit < max_value - min_value)
            {
                max_profit = max_value - min_value;
            }

        }

    }

    return max_profit > 0 ? max_profit : 0;
}
