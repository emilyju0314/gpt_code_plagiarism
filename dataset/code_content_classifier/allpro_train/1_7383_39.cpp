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
        int sumv1 = 0, sumv2 = 0;

        vector<int> v1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            v1.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            sumv1 = sumv1 + v1[i];
        }

        vector<int> v2;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin>>y;
            v2.push_back(y);
        }
        for (int i = 0; i < n; i++)
        {
            sumv2 = sumv2 + v2[i];
        }

        

        if (sumv1 == sumv2)
        {
            int m=0;
            for(int i=0; i<n; i++){
            if(v1[i]>v2[i]){
                m = m + (v1[i]-v2[i]);
            }
        }
        cout<<m<<endl;
            for (int i = 0; i < n; i=i+0)
            {
                if (v1[i] > v2[i])
                {
                    v1[i]--;
                    cout << i + 1 << " ";
                    for (int j = 0; j < n; j++)
                    {
                        if (v1[j] < v2[j])
                        {
                            v1[j]++;
                            cout << j + 1 << endl;
                            break;
                        }
                    }
                }
                else{
                    i++;
                }
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}