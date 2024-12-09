void randn(double mean, double stdv, double *x1, double *x2)
{
    double z1=(double)rand()/RAND_MAX;
    double z2=(double)rand()/RAND_MAX;
    
    *x1=sqrt(-2.0*log(z1))*cos(2.0*PI*z2);
    *x2=sqrt(-2.0*log(z1))*sin(2.0*PI*z2);
    
    *x1=stdv*(*x1)+mean;
    *x2=stdv*(*x2)+mean;
}