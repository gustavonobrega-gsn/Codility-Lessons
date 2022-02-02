#include <unordered_set>

int solution(vector<int> &A) 
{
    unsigned int max_value = 100000;

    std::unordered_set<int> elem_set;

    for (int elem : A)
    {
        elem_set.insert(elem);
    }

    for(int i = 1 ; i <= max_value ; i++)
    {
        if (elem_set.find(i) == elem_set.end())
        {
            return i;
        }
    }

    return max_value+1;
}

