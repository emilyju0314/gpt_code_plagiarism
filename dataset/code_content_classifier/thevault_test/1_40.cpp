double gaussian_chain_full_ZIntegral(gaussian_chain * a_HEAD, gaussian_chain * b_HEAD, double rz[3])
{
    double result;

    result = 0;
    gaussian_chain * a_temp, * b_temp;
    
    a_temp = a_HEAD;

    while(a_temp->NEXT != NULL)
    {
        b_temp = b_HEAD;
        while(b_temp->NEXT != NULL)
        {
            result += gaussian_chain_ZIntegral(a_temp,b_temp,rz);

            b_temp = b_temp->NEXT;
        }
        result += gaussian_chain_ZIntegral(a_temp,b_temp,rz);
        a_temp = a_temp->NEXT;
    }

    b_temp = b_HEAD;
    while(b_temp->NEXT != NULL)
    {
        result += gaussian_chain_ZIntegral(a_temp,b_temp,rz);
        
        b_temp = b_temp->NEXT;
    }

    result += gaussian_chain_ZIntegral(a_temp,b_temp,rz);

    return result;
}