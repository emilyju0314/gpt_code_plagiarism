#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool judgePrimeNumber( int a )
{
    for( int i = 2; i <= sqrt(a); i++ )
        if( a % i == 0 )
            return false;
    return true;
}

int main()
{
    int n, a[10001];
    vector<int> p;

    for( int i = 2; i < 10000; i++ )
        if( judgePrimeNumber(i) )
            p.push_back(i);

    for( int i = 0; i < 10001; i++ )
        a[i] = 0;

    int pluscnt = 1;
    while( pluscnt <= p.size() )
    {
        for( int i = 0; i < p.size(); i++ )
        {
            int sum = 0;
            for( int j = i; j < p.size() && j < pluscnt + i; j++ )
                sum += p[j];
            if( sum <= 10000 )
                a[sum]++;
        }
        pluscnt++;
    }

    while( cin >> n )
    {
        if( n == 0 )
            break;
        cout << a[n] << endl;
    }
    return 0;
}

