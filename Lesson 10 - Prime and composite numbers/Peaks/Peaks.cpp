#include <math.h>

int solution(vector<int> &A)
{
    std::vector<unsigned int> peak_indexes;

    for (unsigned int i = 1 ; i < A.size()-1 ; i++)
    {
        if (A[i-1] < A[i] && A[i] > A[i+1])
        {
            peak_indexes.push_back(i);
            i++;
        }
    }

    if (peak_indexes.size() == 0)
    {
        return 0;
    }

    //test cases sizes
    std::vector<unsigned int> test_cases_sizes_vector;
    std::vector<unsigned int> test_cases_minors_sizes_vector;

    unsigned int divisor_until = sqrt(A.size());

    for (unsigned int i = 2 ; i <= divisor_until ; i++)
    {
        if (A.size() % i == 0)
        {
            //minimum block size is 3
            if (i > 2)
            {
                test_cases_sizes_vector.push_back(A.size() / i);
            }
            test_cases_minors_sizes_vector.insert(test_cases_minors_sizes_vector.begin(),i);
        }
    }

    //merge vectors
    for (unsigned int elem : test_cases_minors_sizes_vector)
    {
        test_cases_sizes_vector.push_back(elem);
    }

    while (!test_cases_sizes_vector.empty())
    {
        unsigned int max_potential_blocks = test_cases_sizes_vector[0];
        test_cases_sizes_vector.erase(test_cases_sizes_vector.begin());

        unsigned int current_block_size = A.size() / max_potential_blocks;

        unsigned int current_block = 0;
        for (unsigned int peak_indexes_current_index = 0 ; current_block < max_potential_blocks && peak_indexes_current_index < peak_indexes.size() ; current_block++)
        {
            unsigned int max_value_current_block = (current_block+1) * current_block_size;
            if (peak_indexes[peak_indexes_current_index] >= max_value_current_block)
            {
                break;
            }

            while (peak_indexes_current_index < peak_indexes.size() && peak_indexes[peak_indexes_current_index] < max_value_current_block)
            {
                peak_indexes_current_index++;
            }
        }

        if (current_block == max_potential_blocks)
        {
            return max_potential_blocks;
        }
    }

    return 1;
}