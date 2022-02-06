#include <vector>

int solution(string &S) 
{
    std::vector<char> char_vector;

    for (char elem : S)
    {
        if (elem == '(')
        {
            char_vector.push_back(elem);
        }

        else if (elem == ')')
        {
            if (char_vector.empty() || char_vector.back() != '(')
            {
                return 0;
            }
            else
            {
                char_vector.pop_back();
            }
        }
    }

    return char_vector.empty() ? 1 : 0;
}
