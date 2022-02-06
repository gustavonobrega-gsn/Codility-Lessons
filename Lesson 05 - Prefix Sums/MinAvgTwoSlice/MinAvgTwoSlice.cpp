int solution(vector<int> &A) 
{
    int P = 0;
    int min_P = 0;
    unsigned int Q = 1;

    int current_sum = A[Q] + A[P];
    float min_average = (float)current_sum / 2.0f;

    int slice_size = 2;

    for (Q = 2 ; Q < A.size() ; Q++)
    {
        slice_size++;
        current_sum += A[Q];

        float current_average = (float)current_sum / (float)slice_size;

	    float average_last_elem = (float)(A[Q-1] + A[Q]) / 2.0f;

        if (average_last_elem < current_average)
        {
        	P = Q-1;
            current_sum = A[Q-1] + A[Q];
            slice_size = 2;

            current_average = average_last_elem;
        }

        if (current_average < min_average)
        {
            min_P = P;
            min_average = current_average;
        }

    }

    return min_P;
   
}