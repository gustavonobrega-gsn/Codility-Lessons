int solution(vector<int> &H) 
{
    std::vector<int> height_stack;

    int count_blocks = 0;

    for (int elem : H)
    {
        if (height_stack.empty() || elem > height_stack.back())
        {
            count_blocks++;
            height_stack.push_back(elem);
        }

        else
        {
            while (elem < height_stack.back())
            {
                height_stack.pop_back();
            }

            if (height_stack.empty() || elem != height_stack.back())
            {
                count_blocks++;
                height_stack.push_back(elem);
            }
        }

    }

    return count_blocks;
}
