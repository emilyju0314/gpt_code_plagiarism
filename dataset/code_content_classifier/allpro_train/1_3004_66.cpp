#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> arr)
{
    int N = arr.size();
    bool flag = false, a0 = true;
    for(int i=0; i<N; ++i)
    {
        if(arr[i] == 1) flag = true;
        if(arr[i] != 0) a0 = false;
    }
    if(a0) return 0;
    if(!flag)
    {
        for(int i=0; i<N; ++i) arr[i] /= 2;
        return 2*solve(arr);
    }
    int ans = 0;
    for(int i=0; i<=N-1; ++i)
        if( ((N-1)&i) == i ) ans ^= arr[i]&1;
    return ans;
}

int main()
{
    int N; scanf("%d", &N);
    vector<int> arr;
    for(int i=0; i<N; ++i)
    {
        int t;
        scanf("%1d", &t);
        arr.push_back(t-1);
    }
    printf("%d\n", solve(arr));
}