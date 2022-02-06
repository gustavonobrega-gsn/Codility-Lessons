int solution(vector<int> &A)
{
    int right_best_sum_ending = 0;
    vector<int> right_best_sum_ending_vector;
    right_best_sum_ending_vector.push_back(0);

    int left_best_sum_ending = 0;
    vector<int> left_best_sum_ending_vector;
    left_best_sum_ending_vector.push_back(0);

    for (unsigned int i = 1, j = A.size() - 2 ; i < A.size()-2 ; i++, j--)
    {
        //since X can be moved to Y-1, worst case from X to Y is 0. Same to Y to Z 
        right_best_sum_ending += A[i];
        if (right_best_sum_ending < 0)
        {
            right_best_sum_ending = 0;
        }
        right_best_sum_ending_vector.push_back(A[i] > right_best_sum_ending ? A[i] : right_best_sum_ending);

        left_best_sum_ending += A[j];
        if (left_best_sum_ending < 0)
        {
            left_best_sum_ending = 0;
        }
        left_best_sum_ending_vector.push_back(A[j] > left_best_sum_ending ? A[j] : left_best_sum_ending);

    }

    int max_sum = 0;
    for (unsigned int i = 0, j = left_best_sum_ending_vector.size() - 1 ; i < right_best_sum_ending_vector.size() ; i++, j--)
    {
        int sum = right_best_sum_ending_vector[i] + left_best_sum_ending_vector[j];

        max_sum = max_sum > sum ? max_sum : sum;
    }

    return max_sum;
}