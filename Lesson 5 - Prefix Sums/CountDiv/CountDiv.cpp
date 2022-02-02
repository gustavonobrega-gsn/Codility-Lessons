int solution(int A, int B, int K) 
{
    int result = B / K;
    result -= A / K;

    if (A % K == 0)
    {
        result++;
    }

    return result;
}