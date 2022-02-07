#include <math.h>
#include <unordered_map>

vector<int> solution(vector<int> &A)
{
    std::unordered_map<unsigned int, unsigned int> elem_count_map;

    //add each element on a map counting the times it appears
    for (unsigned int i = 0 ; i < A.size() ; i++)
    {
        if (elem_count_map.find(A[i]) == elem_count_map.end())
        {
            elem_count_map[A[i]] = 0;
        }

        elem_count_map[A[i]]++;
    }

    vector<int> not_divisors_count_vector;
    std::unordered_map<int,int> divisors_count_map;

    for (unsigned int i = 0 ; i < A.size() ; i++)
    {
        unsigned int elem = A[i];
        if (divisors_count_map.find(elem) == divisors_count_map.end())
        {
            //start counting elements with same value
            int divisors_count = elem_count_map[elem];

            //count 1's if we are not dealing with 1, as we already counted on the previous command
            if (elem != 1)
            {
                divisors_count += elem_count_map[1];
            }

            //get divisors for each elem in the array
            unsigned int elem_last_divisor = sqrt(elem);
            for (unsigned int potential_divisor = 2 ; potential_divisor <= elem_last_divisor ; potential_divisor++)
            {
                //if potential_divisor is divisor
                if (elem % potential_divisor == 0)
                {
                    //if potential_divisor is on the array
                    if (elem_count_map.find(potential_divisor) != elem_count_map.end())
                    {
                        divisors_count += elem_count_map[potential_divisor];
                    }

                    //if the other part of potential_divisor located after the square is on the array and the parts are not the same
                    unsigned int potential_divisor_other_part = elem / potential_divisor;
                    if (elem_count_map.find(potential_divisor_other_part) != elem_count_map.end() && potential_divisor != potential_divisor_other_part)
                    {
                        divisors_count += elem_count_map[potential_divisor_other_part];
                    }
                }
            }

            divisors_count_map[elem] = divisors_count;
        }

        not_divisors_count_vector.push_back(A.size() - divisors_count_map[elem]);
    }

    return not_divisors_count_vector;
}