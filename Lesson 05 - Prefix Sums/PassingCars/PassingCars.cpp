int solution(vector<int> &A) 
{
    int max_cars = 1000000000;

    int current_pairs = 0;
    int total_pairs = 0;

    for (int i = A.size()-1 ; i >= 0 ; i--)
    {
        if (A[i] == 1)
        {
            current_pairs++;
            if (current_pairs > max_cars)
            {
                return -1;
            }
        }

        else if (A[i] == 0)
        {
            total_pairs += current_pairs;

            if (total_pairs > max_cars)
            {
                return -1;
            }
        }
    }


    return total_pairs;
}
