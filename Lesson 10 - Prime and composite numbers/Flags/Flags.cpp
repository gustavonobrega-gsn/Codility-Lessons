#include <math.h>

int solution(vector<int> &A)
{
    std::vector<unsigned int> distance_between_peaks_vector;

    unsigned int distance_between_peaks = 0;
    unsigned int total_distance_between_peaks = 0;

    for (unsigned int i = 1 ; i < A.size()-1 ; i++, distance_between_peaks++)
    {
        if(A[i-1] < A[i] && A[i] > A[i+1])
        {
            distance_between_peaks_vector.push_back(distance_between_peaks);

            total_distance_between_peaks += distance_between_peaks;

            i++;
            distance_between_peaks = 1;
        }
    }

    // for zero and 1 peak, max flags is itself
    if (distance_between_peaks_vector.size() <= 1)
    {
    	return distance_between_peaks_vector.size();
    }

    //not considering first element as it is the first so there is no delta with previous
    distance_between_peaks_vector.erase(distance_between_peaks_vector.begin());

    //max possible number of flags obeying the rule of flag by distance that would fit on the distance between first and last peak would be the value if the 
	//flags are simetric distanced between each other. In this case, the value is equals to the square plus considering the first element
    unsigned int max_flags = sqrt(total_distance_between_peaks) + 1;

    //test from the max possible value to 2
    while (max_flags > 1)
    {
    	//start with first flag on the first peak
    	unsigned int flag_count = 1;
    	unsigned int current_distance = 0;

    	for (unsigned int elem : distance_between_peaks_vector)
    	{
    		current_distance += elem;

    		if (current_distance >= max_flags)
    		{
    			current_distance = 0;
    			flag_count++;
    		}
    	}

    	if (flag_count >= max_flags)
    	{
    		return max_flags;
    	}

    	max_flags--;
    }

    return max_flags;
}