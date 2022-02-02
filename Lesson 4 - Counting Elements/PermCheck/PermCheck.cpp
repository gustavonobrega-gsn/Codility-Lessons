#include <unordered_set>

int solution(vector<int> &A) 
{
    std::unordered_set<int> value_set;

    for (unsigned int i = 1 ; i <= A.size() ; i++)
    {
        if (value_set.find(i) != value_set.end())
        {
            return 0;
        }
        value_set.insert(i);
    }

    for (int value : A)
    {
        value_set.erase(value);
    }

    if (value_set.empty())
    {
        return 1;
    }

    return 0;
}
