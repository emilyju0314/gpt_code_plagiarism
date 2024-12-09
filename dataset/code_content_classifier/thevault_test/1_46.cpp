void orbital_S_matrix(gsl_matrix * dest, orbital * HEAD)
{
    orbital * temp1, * temp2;

    temp1 = HEAD;
    temp2 = HEAD;

    int i,j;

    i = 0;
    j = 0;


    while(temp1->NEXT!=NULL)
    {
        while(temp2->NEXT != NULL)
        {
            gsl_matrix_set(dest,i,j,orbital_SIntegral(temp1,temp2));
            j++;
            temp2 = temp2->NEXT;
        }
        gsl_matrix_set(dest,i,j,orbital_SIntegral(temp1,temp2));
        j = 0;
        temp2 = HEAD;

        temp1 = temp1->NEXT;
        i++;
    }

    while(temp2->NEXT != NULL)
    {
        gsl_matrix_set(dest,i,j,orbital_SIntegral(temp1,temp2));
        j++;
        temp2 = temp2->NEXT;
    }
    
    gsl_matrix_set(dest,i,j,orbital_SIntegral(temp1,temp2));
}