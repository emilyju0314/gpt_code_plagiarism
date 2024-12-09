double orbital_JIntegral(orbital * a, orbital * b)
{
    double result;

    result = 0;
    gaussian_chain * a_head, * b_head, * a_temp, * b_temp;
    a_head = gaussian_chain_calloc();
    b_head = gaussian_chain_calloc();

    single_electron_transform(a_head,a);
    single_electron_transform(b_head,b);

    a_temp = a_head;

    while(a_temp->NEXT != NULL)
    {
        b_temp = b_head;
        while(b_temp->NEXT != NULL)
        {
            result += gaussian_chain_JIntegral(a_temp,b_temp);

            b_temp = b_temp->NEXT;
        }
        result += gaussian_chain_JIntegral(a_temp,b_temp);
        a_temp = a_temp->NEXT;
    }

    b_temp = b_head;
    while(b_temp->NEXT != NULL)
    {
        result += gaussian_chain_JIntegral(a_temp,b_temp);
        
        b_temp = b_temp->NEXT;
    }

    result += gaussian_chain_JIntegral(a_temp,b_temp);

    gaussian_chain_free(a_head);
    gaussian_chain_free(b_head);

    return result;
}