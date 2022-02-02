#include <unordered_set>

int solution(vector<int> &A) 
{
    std::unordered_set<int> set_elem;

    for (unsigned int i = 1 ; i <= A.size()+1 ; i++)
    {
        set_elem.insert(i);
    }

    for (int elem: A)
    {
        set_elem.erase(elem);
    }

    return *set_elem.begin();

}