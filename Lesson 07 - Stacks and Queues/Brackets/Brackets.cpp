#include <vector>

int solution(string &S) 
{
    std::vector<char> char_stack;

    for (unsigned int i = 0 ; i < S.length() ; i++)
    {
        if (S.at(i) == '{' || S.at(i) == '[' || S.at(i) == '(' )
        {
            char_stack.push_back(S.at(i));
        }

        else if (S.at(i) == '}')
        {
            if (char_stack.empty() || char_stack.back() != '{')
            {
                return 0;
            }

            char_stack.pop_back();
        }

        else if (S.at(i) == ']')
        {
            if (char_stack.empty() || char_stack.back() != '[')
            {
                return 0;
            }

            char_stack.pop_back();
        }

        else if (S.at(i) == ')')
        {
            if (char_stack.empty() || char_stack.back() != '(')
            {
                return 0;
            }

            char_stack.pop_back();
        }
    }

    return char_stack.empty() ? 1 : 0;

}
