void gaussian_chain_second_derivative(gaussian_chain * dest, gaussian_chain * src, int key)
{
    gaussian_chain * temp1, * temp2, * temp3;

    temp1 = dest;
    temp2 = src;
    temp3 = gaussian_chain_calloc();
    
    gaussian_chain_derivative(temp3,temp2,key);
    gaussian_chain_derivative(temp1,temp3,key);

    gaussian_chain_free(temp3);
}