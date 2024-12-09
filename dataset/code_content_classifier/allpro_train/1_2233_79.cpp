#include <iostream>
#include <string>
using namespace std;
int main()
{
string s;
cin>>s;
int n = s.size();
int ans=0;
int l=0;
int i=0;
while(i<n)
{
if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T')
{
l++;
}
else
{
l=0;
}
if(l>ans)
{ans=l;
}
i++;
}
cout<<ans<<endl;
return 0;
}