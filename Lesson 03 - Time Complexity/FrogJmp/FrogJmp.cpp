int solution(int X, int Y, int D) 
{
    int result = (Y-X) / D;
    if (( (Y-X) % D ) >0 )
    {
        result++;
    }
    return result;
}

