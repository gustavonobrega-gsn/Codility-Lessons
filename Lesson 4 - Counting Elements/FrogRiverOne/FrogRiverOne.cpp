#include <unordered_set>

int solution(int X, vector<int> &A) 
{
    std::unordered_set<int> leafs_set;

    for (int i = 1 ; i <= X ; i++)
    {
        leafs_set.insert(i);
    }

    int count = 0; 
    for (int leaf : A)
    {
        leafs_set.erase(leaf);

        if(leafs_set.empty())
        {
            return count;
        }
        
        count++;
    }

    return -1;

}
