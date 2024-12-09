void gaussian_chain_derivative(gaussian_chain * dest, gaussian_chain * src, int key)
{
    gaussian_chain * temp1, * temp2;

    int i;

    temp1 = dest;
    temp2 = src;

    while(temp2->NEXT != NULL)
    {
        if(temp2->a[key] == 0)
        {
            for(i=0;i<3;i++)
            {
                temp1->a[i] = temp2->a[i];
                temp1->R[i] = temp2->R[i];
            }
            temp1->a[key] = temp2->a[key] + 1;
            temp1->coefficient = - temp2->coefficient * 2.0 * temp2->exponent;
            temp1->exponent = temp2->exponent;
            temp1->NEXT = gaussian_chain_calloc();
            temp1 = temp1->NEXT;
            temp2 = temp2->NEXT;
        }
        else
        {
            for(i=0;i<3;i++)
            {
                temp1->a[i] = temp2->a[i];
                temp1->R[i] = temp2->R[i];
            }
            temp1->a[key] = temp2->a[key] + 1;
            temp1->coefficient = - temp2->coefficient * 2.0 * temp2->exponent;
            temp1->exponent = temp2->exponent;
            temp1->NEXT = gaussian_chain_calloc();
            temp1 = temp1->NEXT;
            for(i=0;i<3;i++)
            {
                temp1->a[i] = temp2->a[i];
                temp1->R[i] = temp2->R[i];
            }
            temp1->coefficient = (double) temp2->a[key] * temp2->coefficient;
            temp1->exponent = temp2->exponent;
            temp1->a[key] = temp2->a[key] - 1;
            temp1->NEXT = gaussian_chain_calloc();
            temp1 = temp1->NEXT;
            temp2 = temp2->NEXT;
        }

    }

    if(temp2->a[key] == 0)
    {
        for(i=0;i<3;i++)
        {
            temp1->a[i] = temp2->a[i];
            temp1->R[i] = temp2->R[i];
        }
        temp1->a[key] = temp2->a[key] + 1;
        temp1->coefficient = - temp2->coefficient * 2.0 * temp2->exponent;
        temp1->exponent = temp2->exponent;
        temp1->NEXT = gaussian_chain_calloc();
        temp1 = temp1->NEXT;
    }
    else
    {
        for(i=0;i<3;i++)
        {
            temp1->a[i] = temp2->a[i];
            temp1->R[i] = temp2->R[i];
        }
        temp1->a[key] = temp2->a[key] + 1;
        temp1->coefficient = - temp2->coefficient * 2.0 * temp2->exponent;
        temp1->exponent = temp2->exponent;
        temp1->NEXT = gaussian_chain_calloc();
        temp1 = temp1->NEXT;
        for(i=0;i<3;i++)
        {
            temp1->a[i] = temp2->a[i];
            temp1->R[i] = temp2->R[i];
        }
        temp1->coefficient = (double) temp2->a[key] * temp2->coefficient;
        temp1->exponent = temp2->exponent;
        temp1->a[key] = temp2->a[key] - 1;
    }
}