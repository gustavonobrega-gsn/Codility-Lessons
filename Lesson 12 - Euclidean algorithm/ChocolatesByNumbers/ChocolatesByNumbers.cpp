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

int solution(int N, int M) 
{
    //the answer is gonna be N / greatest_common_divisor(N, M)
    
    return N/gcd(N, M);
}