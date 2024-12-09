double f(int k, int a, int b, double PA, double PB)
{
    int i;
    double result;
    result = 0;
    
    for(i=0;i<=k;i++)
    {
        if(a<i||b-k+i<0) continue;
        if(abs(PA)<1e-10&&a-i==0&&abs(PB)<1e-19&&b-k+i==0) result += Binomials(a,i) * Binomials(b,k-i);
        else if(abs(PA)<1e-10&&a-i==0) result += Binomials(a,i) * Binomials(b,k-i)* pow(PB,b-k+i);
        else if(abs(PB)<1e-19&&b-k+i==0) result += Binomials(a,i) * Binomials(a,k-i) * pow(PA,a-i);
        else result += Binomials(a,i) * Binomials(a,k-i) * pow(PA,a-i) * pow(PB,b-k+i);
    }

    return result;
}