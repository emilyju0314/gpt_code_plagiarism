#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n, counter = 0;
    cin >> n;
    long long blocks = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        blocks += arr[i];
    }
    for (int i = n; i != 0; i--)
    {
        if (blocks < i * (i - 1) / 2)
        {
            cout << "NO\n";
            return 0;
        }
        blocks -= arr[i-1];
    }
    cout << "YES\n";
    return 0;
}
int main()
{
    //write your code from here
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        func();
    }
    return 0;
}
