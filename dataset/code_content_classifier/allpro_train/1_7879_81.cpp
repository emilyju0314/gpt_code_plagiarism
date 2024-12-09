#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;vector<int>a;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int b;cin>>b;a.push_back(b);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    cout<<a.size()<<endl;
}
