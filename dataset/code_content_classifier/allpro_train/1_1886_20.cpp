#include <bits/stdc++.h>
using namespace std;

int n,arr[100000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    sort(arr,arr+n);
    int ans=0;
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n && arr[i]==arr[j];j++);
        if(j-i>arr[i]) ans += j-i-arr[i];
        else if(j-i<arr[i]) ans += j-i;
    }
    printf("%d\n",ans);

    return 0;
}
