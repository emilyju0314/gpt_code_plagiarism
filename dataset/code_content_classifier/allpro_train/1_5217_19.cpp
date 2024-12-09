#include<math.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
int func(int m, int n)
{
    int temp = 0;
    if (m <= n) 
    {
        temp = m;
        m = n;
        n = temp;
    }
    int d = m % n;
    if (d == 0) return n;
    else return func(n, d);
}
void  func()
{
    string A, B;
    cin >> A >> B;

    int s1 = A.size();
    int s2 = B.size();

    int lcm = s1 * s2 / func(s1, s2);

    string cad1, cad2;

    for (int i = 0; i < lcm / s1; i++)
    {
        cad1 += A;
    }

    for (int i = 0; i < lcm / s2; i++)
    {
        cad2 += B;
    }

    if (cad1 == cad2)
    {
        cout << cad1 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }
    return 0;
}