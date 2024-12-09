#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        a[i] = m;
    }
   if( prev_permutation(a, a + n)!=false)
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i == n - 1)cout << endl;
        if (i != n - 1)cout << " ";
    }

   next_permutation(a, a + n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i == n - 1)cout << endl;
            if (i != n - 1)cout << " ";
       }
       if( next_permutation(a, a + n)!=false)
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i == n - 1)cout << endl;
            if (i != n - 1)cout << " ";
        }
}
