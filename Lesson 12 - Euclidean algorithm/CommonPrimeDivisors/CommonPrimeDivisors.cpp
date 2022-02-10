unsigned int gcd(int N, int M)
{
    unsigned int remain = N % M;
    if (remain == 0)
    {
        return M;
    }
    else
    {
        return gcd(M,remain);
    }
}

int solution(vector<int> &A, vector<int> &B)
{
	int count_same_prime_divisors = 0;

	for (unsigned int i = 0 ; i < A.size() ; i++)
	{
        if(A[i] == 1 && B[i] == 1)
        {
            count_same_prime_divisors++;
        }
        else 
        {
            unsigned int gcd_A_B = gcd(A[i],B[i]);

            //if greatest_common_divisor(A[i], B[i]) is 1, A[i] and B[i] don't share prime divisors
            if (gcd_A_B > 1)
            {
                unsigned int gcd_A = gcd_A_B;
                do
                {
                    A[i] = A[i] / gcd_A;
                    
                    //if A[i] is 1, then, it shares prime divisors with greatest_common_divisor(A[i], B[i])
                    if (A[i] == 1)
                    {
                        unsigned int gcd_B = gcd_A_B;

                        do
                        {
                            //if B[i] is 1, then, it shares prime divisors with greatest_common_divisor(A[i], B[i])
                            B[i] = B[i] / gcd_B;

                            if (B[i] == 1)
                            {
                                count_same_prime_divisors++;
                            }
                            else
                            {
                                gcd_B = gcd(B[i],gcd_A_B);
                            }


                        }while (B[i] != 1 && gcd_B != 1);

                    }
                    else
                    {
                        gcd_A = gcd(A[i],gcd_A_B);
                    }

                }while (A[i] != 1 && gcd_A != 1);
            }
        }
    }
    return count_same_prime_divisors;
}