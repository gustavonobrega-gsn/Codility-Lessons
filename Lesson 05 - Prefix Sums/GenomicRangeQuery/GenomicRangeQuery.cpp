vector<int> solution(string &S, vector<int> &P, vector<int> &Q) 
{
    vector<int> result;

    typedef struct impact_count_
    {
        unsigned int A_count = 0;
        unsigned int C_count = 0;
        unsigned int G_count = 0;
    } impact_count;

    vector<impact_count> impact_count_vector;

    impact_count first_impact;

    impact_count_vector.push_back(first_impact);

    for (unsigned int i = 0 ; i < S.length() ; i++)
    {
        impact_count current_impact_count;

        current_impact_count = impact_count_vector[impact_count_vector.size()-1];
        
        switch (S.at(i))
        {
            case 'A':
                current_impact_count.A_count++;
                break;
            case 'C':
                current_impact_count.C_count++;
                break;
            case 'G':
                current_impact_count.G_count++;
                break;
            default:
                break;
        }

        impact_count_vector.push_back(current_impact_count);
    }

    for (unsigned int i = 0 ; i < P.size() ; i++)
    {
        if (impact_count_vector[P[i]].A_count != impact_count_vector[Q[i]+1].A_count)
        {
            result.push_back(1);
        }

        else if (impact_count_vector[P[i]].C_count != impact_count_vector[Q[i]+1].C_count)
        {
            result.push_back(2);
        }

        else if (impact_count_vector[P[i]].G_count != impact_count_vector[Q[i]+1].G_count)
        {
            result.push_back(3);
        }

        else 
        {
            result.push_back(4);
        }
    }

    return result;
}