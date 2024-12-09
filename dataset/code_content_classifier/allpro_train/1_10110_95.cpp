 #include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
set<string>s;
  string ss;
  while(n--) 
  {cin>>ss; s.insert(ss); }
  cout<<s.size()<<endl;
  
}
