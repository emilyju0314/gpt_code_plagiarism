double gaussian_chain_get(gaussian_chain * HEAD,double x,double y, double z)
{
    gaussian_chain * temp;

    double result;

    result = 0;

    temp = HEAD;
    result += pow(x - temp->R[0], temp->a[0]) * pow(y - temp->R[1],temp->a[1]) * pow(z - temp->R[2],temp->a[2]) * exp(- temp->exponent * ((x - temp->R[0]) * (x - temp->R[0]) + (y - temp->R[1]) * (y - temp->R[1]) + (z - temp->R[2]) * (z - temp->R[2])));

    while(temp->NEXT != NULL)
    {
        temp = temp->NEXT;
        result += pow(x - temp->R[0], temp->a[0]) * pow(y - temp->R[1],temp->a[1]) * pow(z - temp->R[2],temp->a[2]) * exp(- temp->exponent * ((x - temp->R[0]) * (x - temp->R[0]) + (y - temp->R[1]) * (y - temp->R[1]) + (z - temp->R[2]) * (z - temp->R[2])));
    }

    return result;
}