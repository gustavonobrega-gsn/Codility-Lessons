int solution(vector<int> &A, vector<int> &B) 
{
    int fishes_alive = 0;

    std::vector<int> fish_stack_upstream;
    std::vector<int> fish_stack_downstream;

    //downstream 1, upstream 0
    for (unsigned int i = 0 ; i < A.size() ; i++)
    {
        if (B[i] == 0)
        {
            if (fish_stack_downstream.empty())
            {
                fishes_alive++;
            }
            else 
            {
                fish_stack_upstream.push_back(A[i]);
                
                while (!fish_stack_downstream.empty() && !fish_stack_upstream.empty())
                {
                    fish_stack_downstream.back() > fish_stack_upstream.back() ? fish_stack_upstream.pop_back() : fish_stack_downstream.pop_back();
                }

                if (!fish_stack_upstream.empty())
				{
					fishes_alive += fish_stack_upstream.size();
					fish_stack_upstream.clear();
				}
            }
        }

        else if (B[i] == 1)
        {
            fish_stack_downstream.push_back(A[i]);
        }
    }

    return fishes_alive + fish_stack_downstream.size() + fish_stack_upstream.size();
}
