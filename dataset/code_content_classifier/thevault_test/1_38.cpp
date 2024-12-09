void two_electron_transform(gaussian_chain * HEAD, orbital * a, orbital * b)
{
    gaussian_chain * temp, *bk;

    temp = HEAD;

    orbital * temp1, * temp2;

    int i,j,k,l;

    int q;

    int p[3];

    double coefficient;

    double xi;
    double zeta;
    double P[3];
    double PA[3];
    double PB[3];
    double AB;

    AB = 0;
    for(i=0;i<3;i++)
        AB += (a->cartesian[i]-b->cartesian[i])*(a->cartesian[i]-b->cartesian[i]);

    for(i=0;i<a->length;i++)
    {
        for(j=0;j<a->total;j++)
        {
            for(k=0;k<b->length;k++)
            {
                for(l=0;l<b->total;l++)
                {
                    zeta = *(a->exponents + j) + *(b->exponents + l);
                    xi = *(a->exponents + j) * *(b->exponents + l) / zeta;

                    for(q=0;q<3;q++)
                    {
                        P[q] = (*(a->exponents + j) * a->cartesian[q] + *(b->exponents + l) * b->cartesian[q])/zeta;
                        PA[q] = P[q] - a->cartesian[q];
                        PB[q] = P[q] - b->cartesian[q];
                    }
                    
                    for(p[0]=0;p[0]<=(a->A[i].a[0]+b->A[k].a[0]);p[0]++)
                    {
                        for(p[1]=0;p[1]<=(a->A[i].a[1]+b->A[k].a[1]);p[1]++)
                        {
                            for(p[2]=0;p[2]<=(a->A[i].a[2]+b->A[k].a[2]);p[2]++)
                            {

                                coefficient = a->A[i].coef * *(a->coefficients + j) * normalize(*(a->exponents + j),a->A[i].a[0],a->A[i].a[1],a->A[i].a[2]) * b->A[k].coef * *(b->coefficients + l) * normalize(*(b->exponents + l),b->A[k].a[0],b->A[k].a[1],b->A[k].a[2]);
                                coefficient *= tranformation_coefficient(a->A[i].a,b->A[k].a,p,PA,PB,xi,AB);

                                for(q=0;q<3;q++)
                                {
                                    temp->R[q] = P[q];
                                    temp->a[q] = p[q];
                                    temp->exponent = zeta;
                                    temp->coefficient = coefficient;
                                }
                                
                                temp->NEXT = gaussian_chain_calloc();
                                bk = temp;
                                temp = temp->NEXT;
                            }
                        }
                    }
                }
            }
        }
    }
    delete temp;
    bk->NEXT = NULL;
}