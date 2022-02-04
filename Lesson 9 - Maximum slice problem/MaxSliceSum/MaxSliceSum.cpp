int solution(vector<int> &A)
{
    int last_best_sum = A[0];
    int current_sum = last_best_sum;

    for (unsigned int i = 1 ; i < A.size() ; i++)
    {

        if (last_best_sum < 0 && A[i] > last_best_sum)
        {
            last_best_sum = A[i];
        }

        if (current_sum < 0)
        {
            current_sum = 0;
        }

        current_sum += A[i];

        if (last_best_sum < current_sum)
        {
            last_best_sum = current_sum;
        }
    }

    return last_best_sum;
}