vector<int> solution(int N, vector<int> &A) 
{
    int max_value = 0;
    int counting_max_value = 0;

    std::vector<int> result(N,0);

    for (int elem : A)
    {
        if (elem <= N)
        {
            if (result[elem-1] < max_value)
            {
                result[elem-1] = max_value;
            }

            result[elem-1]++;

            if (result[elem-1] > counting_max_value)
            {
                counting_max_value = result[elem-1];
            }
        }

        else if (elem == N+1)
        {
            max_value = counting_max_value;
        }
    }

    for (unsigned int i = 0 ; i < result.size() ; i++)
    {
        if (result[i] < max_value)
        {
            result[i] = max_value;
        }
    }

    return result;

}
