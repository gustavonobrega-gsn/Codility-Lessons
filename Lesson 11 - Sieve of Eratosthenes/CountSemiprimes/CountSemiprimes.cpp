vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
    typedef struct count_semi_primes_
    {
        unsigned int prime_divisor;
        unsigned int semi_primes_so_far;

    }count_semi_primes;

    std::vector<count_semi_primes> count_semi_primes_vector;
    unsigned int semi_primes_so_far = 0;

    for (int i = 0 ; i <= N ; i++)
    {
        count_semi_primes count_semi_primes_elem{0,semi_primes_so_far};
        count_semi_primes_vector.push_back(count_semi_primes_elem);
    }

    for (int i = 2 ; i <= N ; i++)
    {
        if (count_semi_primes_vector[i].prime_divisor == 0)
        {
            for (int j = i << 1 ; j <= N ; j = j+i)
            {
                if (count_semi_primes_vector[j].prime_divisor == 0)
                {
                    count_semi_primes_vector[j].prime_divisor = i;
                }
            }
        }

        else
        {
            //check if its a semi_prime
            //if so, sums one on semi_primes_so_far
            int div = i / count_semi_primes_vector[i].prime_divisor;
            if (count_semi_primes_vector[div].prime_divisor == 0)
            {
                semi_primes_so_far++;
            }
        }

        count_semi_primes_vector[i].semi_primes_so_far = semi_primes_so_far;
    }

    std::vector<int> ret;
    for (unsigned int i = 0 ; i < P.size() ; i++)
    {
        int semi_primes = count_semi_primes_vector[Q[i]].semi_primes_so_far;

        //in case P[i] is a semiprime, it will not be considered on Q[i] - P[i], so we need to increment 1 to consider it
        if (count_semi_primes_vector[P[i]].prime_divisor > 0)
        {
            int div = P[i] / count_semi_primes_vector[P[i]].prime_divisor;
            if (count_semi_primes_vector[div].prime_divisor == 0)
            {
                semi_primes++;
            }
        }

        semi_primes -= count_semi_primes_vector[P[i]].semi_primes_so_far;

        ret.push_back(semi_primes);
    }

    return ret;
}