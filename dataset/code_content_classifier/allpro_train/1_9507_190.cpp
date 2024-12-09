#include <iostream>

using namespace std;
int x,k,i;
int main()
{
    cin>>k>>x;
    for(i=x-k+1;i<=x+k-1;++i)
        cout<<i<<" ";
    return 0;
}
