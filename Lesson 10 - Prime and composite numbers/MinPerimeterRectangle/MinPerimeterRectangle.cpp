#include <math.h>

int solution(int N) 
{
    // junt find the maximum divisor from N and use it
    int max_divisor = sqrt(N);

    while (N % max_divisor != 0 && max_divisor > 1)
    {
        max_divisor--;
    }

    return (max_divisor + (N/max_divisor)) * 2;

}
