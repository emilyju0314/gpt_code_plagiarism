#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define ll long long int

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n, '.'));
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        
        for (int j = 0; j < n; j++)
        {
            a[i][j] = s[j];
            if (a[i][j] == 'X')
            {
                if ((i + j) % 3 == 0)
                    c1++;
                else if ((i + j) % 3 == 1)
                    c2++;
                else
                    c3++;
            }
        }
    }

    int mini;
    int val;
    if (c1 < c2)
    {
        mini = c1;
        val = 0;
    }
    else
    {
        mini = c2;
        val = 1;
    }
    if (c3 < mini)
    {
        mini = c3;
        val = 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'X')
            {
                if ((i + j) % 3 == val)
                    a[i][j] = 'O';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << "\n";
    }
    

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }


    return 0;
}
