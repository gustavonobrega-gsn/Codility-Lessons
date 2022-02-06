#include <unordered_set>

int solution(vector<int> &A) 
{
    std::unordered_set<int> elem_set;

    for (int elem : A)
    {
        elem_set.insert(elem);
    }

    return elem_set.size();

}
