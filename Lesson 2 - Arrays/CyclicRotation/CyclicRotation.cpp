vector<int> solution(vector<int> &A, int K) 
{
    vector<int> rotated_array;

    if (A.size() > 0){

        K = K % A.size();

        unsigned int first_elem_offset_index = A.size() - K;

        for (unsigned int i = 0 ; i < A.size() ; i++)
        {
            unsigned int current_elem_offset_index = (first_elem_offset_index + i) % A.size();
            rotated_array.push_back(A[current_elem_offset_index]);
        }

    }

    return rotated_array;
}
