#include<bits/stdc++.h>
using namespace std;
int a;
int main()
{
    char s[7];
    gets(s);
    for(int i=0;i<=6;i++)
        if(s[i]=='1') a++;
    cout<<a;
}