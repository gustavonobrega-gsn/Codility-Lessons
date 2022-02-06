#include <unordered_set>

int solution(vector<int> &A) 
{
    std::unordered_set<int> paired_set;

    for(int elem : A)
    {
        if (paired_set.find(elem) == paired_set.end())
        {
            paired_set.insert(elem);
        }

        else 
        {
            paired_set.erase(elem);
        }
    }

    return *paired_set.begin();
}