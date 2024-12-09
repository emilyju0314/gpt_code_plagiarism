#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int min = 101, max = 0, mini = -1, maxi = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                mini = i;
            }

            if (a[i] > max)
            {
                max = a[i];
                maxi = i;
            }
        }

        if ((maxi <= n / 2) && (mini <= n / 2))
        {
            int temp;
            if (maxi < mini)
            {
                temp = mini;
            }
            else
            {
                temp = maxi;
            }

            cout << temp + 1 << endl;
            goto a;
        }
        else if ((maxi >= n / 2) && (mini >= n / 2))
        {
            int temp;
            if (maxi < mini)
            {
                temp = maxi;
            }
            else
            {
                temp = mini;
            }

            cout << n - temp << endl;
            goto a;
        }
        else
        {
            if (maxi < mini)
            {
                int temp = mini;
                mini = maxi;
                maxi = temp;
            }

            if (mini <= n - maxi - 1)
            {
                int temp = mini + 1;

                if ((maxi - temp - 1) < (n - maxi - 1))
                {
                    cout << maxi + 1 << endl;
                    goto a;
                }
                else
                {
                    cout << temp + n - maxi << endl;
                    goto a;
                }
            }
            else
            {
                int temp = n - maxi;

                if ((maxi - mini) < (mini))
                {
                    cout << n - mini << endl;
                    goto a;
                }
                else
                {
                    cout << temp + mini + 1 << endl;
                    goto a;
                }
            }
        }

    a:
        int q;
    }

    return 0;
}