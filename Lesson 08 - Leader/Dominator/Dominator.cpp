#include <unordered_map>


int solution(vector<int> &A) 
{
    std::unordered_map<unsigned int, unsigned int> count_map;

    unsigned int max_count = 0;
    unsigned int index_max_count = -1;

    for (unsigned int i = 0 ; i < A.size() ; i++)
    {
        std::unordered_map<unsigned int, unsigned int>::iterator count = count_map.find(A[i]);
        if (count == count_map.end())
        {
            count_map[A[i]] = 1;
            count = count_map.find(A[i]);
        }

        else 
        {
            count->second++;
        }

        if (count->second > max_count)
        {
            max_count = count->second;
            index_max_count = i;
        }
    }

    if (max_count > ( A.size() / 2 ))
    {
        return index_max_count;
    }

    else 
    {
        return -1;
    }
}
