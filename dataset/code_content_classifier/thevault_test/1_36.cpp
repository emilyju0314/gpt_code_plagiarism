double tranformation_coefficient(int a[3], int b[3], int p[3], double PA[3], double PB[3], double xi, double AB)
{
    int i;
    double result;

    result = 1;

    for(i=0;i<3;i++)
        result *= f(p[i],a[i],b[i],PA[i],PB[i]);

    result *= exp(- xi * AB); // it might cause confusion, but AB here has already been squared, meaning AB -> |AB|^2

    return result;
}