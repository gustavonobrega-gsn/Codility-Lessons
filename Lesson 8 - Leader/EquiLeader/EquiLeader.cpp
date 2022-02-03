#include <unordered_map>

typedef struct dominator_
{
    int value;
    int count = -1;
} dominator_struct;

dominator_struct get_dominator(vector<int> &A) 
{
    std::unordered_map<unsigned int, dominator_struct> count_map;

    int max_count = 0;

    dominator_struct dominator_max_count;

    for (unsigned int i = 0 ; i < A.size() ; i++)
    {
        std::unordered_map<unsigned int, dominator_struct>::iterator it = count_map.find(A[i]);
        if (it == count_map.end())
        {
            dominator_struct dominator;
            dominator.value = A[i];
            dominator.count = 1;

            count_map[A[i]] = dominator;

            it = count_map.find(A[i]);
        }

        else 
        {
            it->second.count++;
        }

        if (it->second.count > max_count)
        {
            max_count = it->second.count;
            dominator_max_count = it->second;
        }
    }

    if (max_count > ( A.size() / 2 ))
    {
        return dominator_max_count;
    }

    dominator_max_count.count = -1;
    return dominator_max_count;
}


int solution(vector<int> &A) 
{
    int equi_leaders_count = 0;

    dominator_struct dominator = get_dominator(A);

    int dominator_count_left_side = 0;

    if (dominator.count > 0)
    {
        for (int i = 0 ; dominator_count_left_side < dominator.count ; i++)
        {
            if (A[i] == dominator.value)
            {
                dominator_count_left_side++;
            }

            int dominator_count_right_size = dominator.count - dominator_count_left_side;

            int left_side_size = i + 1;
            int right_side_size = A.size() - left_side_size;

            if ( (dominator_count_left_side > (left_side_size / 2) ) && ( dominator_count_right_size > (right_side_size / 2) ) )
            {
                equi_leaders_count++;
            }
            
        }
    }

    return equi_leaders_count;
}