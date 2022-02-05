#include <math.h>

int solution(int N) 
{
    unsigned int max_potential_factor = sqrt(N);
    //1 is always an initial factor
    unsigned int count_factor = 1;

    for (unsigned int i = 2 ; i <= max_potential_factor ; i++)
    {
        if (N % i == 0)
        {
            count_factor += 2;
        }
    }

    if (max_potential_factor * max_potential_factor != N)
    {
        count_factor++;
    }

    return count_factor;
}
