double two_electron_JIntegral(orbital * a_1, orbital * b_1, orbital * c_2, orbital * d_2)
{
    double result;

    gaussian_chain * temp_1, * temp_2;

    temp_1 = gaussian_chain_calloc();
    temp_2 = gaussian_chain_calloc();

    two_electron_transform(temp_1,a_1,b_1);
    two_electron_transform(temp_2,c_2,d_2);

    result = gaussian_chain_full_JIntegral(temp_1,temp_2);
    
    gaussian_chain_free(temp_1);
    gaussian_chain_free(temp_2);

    return result;
}